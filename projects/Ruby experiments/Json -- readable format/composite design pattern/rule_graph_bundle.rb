require 'json-schema'
require 'logger'
require 'rule_graph_bundle/version'
require 'yajl'
require 'aggregation'
require 'filter'
require 'start'
require 'projection'
require 'output'

module RuleGraphBundle

  class ThalamusGraph
    attr_reader :graph_hash, :root
    attr_writer :logger
    def initialize(graph)
      @graph_hash = graph
      raise 'invalid graph' if graph['type'] != 'start'
      clazz = RuleGraphBundle.const_get(graph['type'].capitalize)
      @root = clazz.new(graph)
    end
  end

  def self.for_each_aggregation(node, &block)
    yield(node) if node.is_a?(Aggregation)
    node.children.each do |child|
      for_each_aggregation(child, &block)
    end
  end

  def self.logger
    @logger ||= Logger.new(STDOUT)
  end

  def self.logger=(logger)
    @logger = logger
  end

  def self.for_each_filter(node, &block)
    yield(node) if node.is_a?(Filter)
    node.children.each do |child|
      for_each_filter(child, &block)
    end
  end

  def self.for_each_projection(node, &block)
    yield(node) if node.is_a?(Projection)
    node.children.each do |child|
      for_each_projection(child, &block)
    end
  end

  def self.for_each_output(node, &block)
    yield(node) if node.is_a?(Output)
    node.children.each do |child|
      for_each_output(child, &block)
    end
  end

  def self.from_hash(graph_bundle)
    json_file = File.new(File.join(File.dirname(File.expand_path(__FILE__)), 'task_graph_schema.json'))
    parsed_schema = Yajl::Parser.parse(json_file)
    errors =  JSON::Validator.fully_validate(parsed_schema, graph_bundle, :errors_as_objects => true)
    unless errors.empty?
      logger.warn "Incorrectly formed src field"
      errors.each do |error|
        logger.warn "#{Yajl::Encoder.encode(error)}"
      end
      return nil
    end
    graph = ThalamusGraph.new(graph_bundle)
    graph.logger = RuleGraphBundle.logger
    graph
  end

  def self.from_json(json_graph_bundle)
    graph_bundle = Yajl::Parser.parse(json_graph_bundle)
    return nil if graph_bundle.nil?
    from_hash(graph_bundle)
  end

end
