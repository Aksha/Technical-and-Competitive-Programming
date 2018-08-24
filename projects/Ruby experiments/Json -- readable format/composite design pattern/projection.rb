module RuleGraphBundle
  class Projection < CompositeNode
    def initialize(desc)
      super(desc)
    end


    def build_projection_query(query_params)
      string_params = query_params.map do |field_key,identifier|
        "\"#{field_key}\":#{identifier}"
      end
      "projection( { \"node_name\": \"#{name}\", \"node_id\": \"#{node_id}\", \"PROJECTION\": { #{string_params.join(',')} } } )"
    end

    def get_projection_query()
      validate_key desc, 'mode'
      mode = desc['mode']
      query = {}
      if mode == 'simple'
        validate_key desc, 'fields_to_project', false
        desc['fields_to_project'].each do |field|
          query[field] = field
        end
        return build_projection_query(query)
      else
        validate_key desc, 'projection_query'
        "projection( {\"node_name\": \"#{name}\", \"node_id\": \"#{node_id}\", \"PROJECTION\":  #{desc['projection_query']}  })"
      end
    end
  end
end
