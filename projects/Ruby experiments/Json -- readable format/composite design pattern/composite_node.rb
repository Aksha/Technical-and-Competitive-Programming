module RuleGraphBundle
  class CompositeNode
    attr_accessor :parents, :children, :node_id, :type, :name, :desc
    KAFKA_VERSION = '0.10.2.1'
    def initialize(desc)
      @desc = desc
      @node_id = desc['node_id']
      @type = nil
      @name = desc['name']
      @children = []
      @parents = []
      add_children
    end
    def add_children
      return unless desc.has_key?('children')
      desc['children'].each do |node|
        clazz = RuleGraphBundle.const_get(node['type'].capitalize)
        composite_node = clazz.new(node)
        composite_node.parents << self
        children << composite_node
      end
    end
    def validate_key(obj,key,emptiness=true)
      raise "#{key} does not exist for aggregation node id #{self.node_id}" unless obj.has_key?"#{key}"
      raise "value of #{key} field is nil for aggregation node id #{self.node_id}!" if obj["#{key}"].nil?
      raise "value of #{key} field is empty for aggregation node id #{self.node_id}" if emptiness and obj["#{key}"].empty?
    end
  end
end
