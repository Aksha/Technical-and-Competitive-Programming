require 'sinatra'
require 'yajl'
require 'yaml'
require 'pg'

db = PG.connect(dbname: 'domo', user: 'akshaya', password: 'domo2018')
config_path = File.join(File.dirname(__FILE__), 'config.yml')
config = YAML::load_file(config_path)

set :bind,config['host']
set :port,config['port']

$h = Hash.new
$num_users = 0


def aggregate_users(params)
 if(!$h.has_key?(params["userInfo"]["email"]))
   $num_users += 1
   $h[params["userInfo"]["email"]] = 1
 elsif ($h.has_key?(params["userInfo"]["email"]))
  $h[params["userInfo"]["email"]] += 1
 end
end

db.prepare('statement1','insert into user_metrics (numusers) values ($1)')
db.prepare('statement2', 'truncate table user_metrics');

post '/api/thalamus_events' do
  if request.body.size > 0
   @params = JSON.parse(request.body.read)
    aggregate_users(@params)
    db.exec_prepared('statement2')
    db.exec_prepared('statement1', [$num_users]);
  end
end
