#!/usr/bin/env ruby

require "Yajl"
require "byebug"

#rgb = RuleGraphBundle::ThalamusGraph.new(graph)
#rgb.convertToTQL(graph)
graph = Yajl::Parser.parse(File.read('input.txt'))
def get_rules(graph)
      rules_arr = []
      rules_arr << graph['query'] if graph['query']
      if (graph['children'])
        nodes = graph['children']
        nodes.each {|node| rules_arr << get_rules(node)} 
      end
      return nil if rules_arr.empty?
      rules_arr.flatten.compact
end


def get_rulename(node)
	return nil unless node['type'].eql?('filter') 
	name = "#{node['name']}_#{node['node_id']}" unless node['name'].empty?
end

## Pull [column value] from object w/o extract semantics
def to_column_value(obj)
	aggr_buffer = []
	if obj.is_a?(Array)
		obj.each do |i|
		next if i.nil? or i.empty?
		  field = to_column_value(i)
		  aggr_buffer << field	if field and field.size.nonzero?
		end
	else
		column = obj['column']
		value = obj['value']
		#if c and v and c.size.nonzero? and v.size.nonzero?
		if column and value and column.size.nonzero?
		  aggr_buffer << column
		  aggr_buffer << value
		end
	end
	return nil if aggr_buffer.empty?
	aggr_buffer.compact
end

def influx_manager(influx)
	temp = {}
	influx.each do |influxKey, influxValue|
		# if table == tablename
        if influxValue.is_a?(String)
        	temp[influxKey] = influxValue	
        # for tags:{extracted:[ {key:val} ]	
        elsif influxValue.is_a?(Hash)	
		    	temp[influxKey]  ||= {}
        	influxValue.each do |ikey, ival|
            	columnValue = to_column_value(ival)
	    		next if columnValue.nil? or columnValue.empty?
            	if ikey.eql?('extracted')
              		columnValue.each do |col,val| 
						if val.is_a?(Array)
	                  		val = val.collect {|i| "#{i}"}	
	                  	elsif val.size.nonzero?
		                    val = "#{val}"
	                	end
	                	temp[influxKey][col] = val
              	    end
            	else  
                    columnValue.each do |col,val| 
                		temp[influxKey][col] = val	
	     			end
            	end
        	end
    	end
    end
    return nil if temp.empty?
    temp
end

def aggregation_nodes(node)

	#to get aggregation type - max, count, min, avg
	aggr_type = node['aggr_type']
	return nil unless node['aggr_type']  

	#declaring a hash object
	aggr_body = {}


	aggr_body['AGGREGATION_NODE_ID'] = node['node_id']  
	return nil unless node['node_id']

	type = node['type']
	return nil  unless node['type']
	
	publish = node['publish']
	return nil unless node['publish']

	dest_sources = publish['dest_sources']
	return nil unless dest_sources

	influx  = dest_sources['influx']
	return nil unless influx
    
    temp = influx_manager(influx)

    aggr_body.merge!(temp)


#converting the hash object back to json
	begin 
		aggr_body = Yajl::Encoder.encode(aggr_body)
	rescue Yajl::ParseError => e
		raise "graph bundle - Yajl::Error #{e.to_s}"
	end 
    [aggr_type, aggr_body]
end


def get_rules_results(graph)
	rules_arr = []
    if (nodes = graph['children'])
        if (rulename = get_rulename(graph))
			aggr_buffer = nodes.collect{|i| aggregation_nodes(i)}
			aggr_buffer.compact!
			if (!aggr_buffer.empty?)
			  aggr_buffer = aggr_buffer.collect{|aggr_type, aggr_body| "#{aggr_type}( #{aggr_body} )"}
			  rules_arr << "ruleresults #{rulename} { #{aggr_buffer.join(',')} }" unless aggr_buffer.empty?
			end
    	end
	    nodes.each do |node|
	      rules_arr << get_rules_results(node)
	      rules_arr.flatten!
	    end
    end
	return nil	if rules_arr.empty?
	rules_arr.flatten.compact
end

def get_rulegraph(graph)
	rules_arr   = []
	if (nodes = graph['children'])
		if (rulename = get_rulename(graph))
		  buffer = nodes.collect { |i| get_rulename(i) }
		  buffer.compact!
		  rules_arr << "rulegraph #{rulename} {#{buffer.join(',')}}" unless buffer.empty?
		end
		nodes.each do |node|
		  rules_arr << get_rulegraph(node)
		  rules_arr.flatten!
		end
	end
	return nil if rules_arr.empty?
	rules_arr.flatten.compact
end




rules = []
rules = get_rules(graph)
puts rules
rule_results = []
rule_results = get_rules_results(graph)
puts rule_results
rule_graph = []
rule_graph = get_rulegraph(graph)
puts rule_graph
