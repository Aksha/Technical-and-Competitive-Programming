require 'composite_node'
module RuleGraphBundle
  class Aggregation < CompositeNode
    def initialize(desc)
      super(desc)
    end

    def alarm_info
      extra = desc['extra']
      ai = extra['alarm_info']
      return nil unless ai['enabled']
      ai
    end

    def window_info
      extra = desc['extra']
      alarm_info = extra['alarm_info']
      return nil unless alarm_info && alarm_info['enabled']
      {'aggr_name' => extra['aggr_name'],
       'aggr_type' => extra['aggr_type'],
       'window_size' => extra['window_size']}
    end


    def get_fields_for_aggregation
      desc['selected_fields']
    end

    def get_aggregation_query()
      tag_string = sanitize_tags desc['group_by'],desc['tags']
      if tag_string.empty?
        "#{desc['aggr_type']}(\"node_name\": \"#{name}\", \"node_id\":\"#{node_id}\",\"args\":[#{get_fields_for_aggregation.join(',')}] )"
      else
        "#{desc['aggr_type']}(\"node_name\": \"#{name}\", \"node_id\":\"#{node_id}\",\"tags\":{#{tag_string}},\"args\":[#{get_fields_for_aggregation.join(',')}] )"
      end

    end

    def sanitize_tags(group_by,tags)
      sanitized_extracted_tags = []
      group_by.each do |extracted|
        sanitized_extracted_tags << "\"#{extracted}\":#{extracted}"
      end
      sanitized_literal_tags = []
      tags.each do |literal|
        sanitized_literal_tags << "\"#{literal['column']}\":\"#{literal['value']}\""
      end
      combined_tags = sanitized_extracted_tags + sanitized_literal_tags
      "#{combined_tags.join(',')}"
    end

    # def create_points(column,selected_fields)
    #   "{\"#{column}\":[#{selected_fields.join(',')}]}"
    # end

  end
end
