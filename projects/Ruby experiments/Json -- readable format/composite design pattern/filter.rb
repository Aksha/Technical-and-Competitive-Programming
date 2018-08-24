module RuleGraphBundle
  class Filter < CompositeNode

    def initialize(desc)
      super(desc)
    end

    def get_filter_query()
      validate_key desc, 'query'
      "rule #{name}_#{node_id}{\n#{desc['query']}\n}"
    end

    def get_adjacency_list
      list = []
      self.children.each do |child|
        list << "#{child.name}_#{child.node_id}" if child.is_a?(Filter)
      end
      list.empty? ? nil : "#{list.join(',')}"		# for empty objects, return nil
    end

  end
end
