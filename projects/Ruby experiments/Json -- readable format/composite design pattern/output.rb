module RuleGraphBundle
  class Output < CompositeNode
    def initialize(desc)
      super(desc)
    end

    def get_output_details
      destination_data_details = desc['destination']['data']
      if destination_data_details['format'] == 'influx'
        return nil if destination_data_details['table'].empty?
        return nil if destination_data_details['column'].empty?
      end
      unless destination_data_details.has_key?('type')
        return kafka_details
      end
      connector_type = destination_data_details['type']
      if connector_type == 'http'
        frontdoor_details
      else
        kafka_details
      end
    end
    def kafka_details
      return nil unless desc['destination'].has_key?('seed_brokers')
      return nil unless desc['destination'].has_key?('topic')
      broker_list = Hash[desc['destination']['seed_brokers'].split(',').map { |k| k.split(':') }]
      return nil if broker_list.empty?
      return nil if desc['destination']['topic'].empty?
      common = {'broker_list' => broker_list,
                'topic_name' => desc['destination']['topic'], 'type' => 'kafka' }
      final = common.merge desc['destination']['data']
      final['kafka_version'] ||= KAFKA_VERSION
      final
    end
    def frontdoor_details
      frontdoor = {}
      return nil unless desc['destination'].has_key?('cluster')
      return nil unless desc['destination'].has_key?('datacenter')
      frontdoor['cluster'] = desc['destination']['cluster']
      frontdoor['datacenter'] = desc['destination']['datacenter']
      frontdoor.merge desc['destination']['data']
    end
  end
end
