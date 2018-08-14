require 'pg'
require 'elasticsearch'
require 'date'

db = PG.connect(dbname: 'domo', user: 'akshaya', password: 'domo2018')
client = Elasticsearch::Client.new host: 'bb0706.target.com:9200'

from = 0
size = 0

body = {
    'from' => from,
    'size' => size,
    'query' => {
        'bool' => {
            'must' => { 'match_all' => {} }
        }
    }
}

today = DateTime.now
alarmInfo = 0
for i in 1..7
        now = today - i
        now_formatted = now.strftime("%Y-%m-%d")
        deliveryRequests_time = now_formatted + "_deliveryrequests"
        result = client.search(index: deliveryRequests_time, body: body)
        alarmInfo += result["hits"]["total"]
end
db.prepare('statement1', 'insert into alarms_metrics (alarms) values ($1)')
db.exec_prepared('statement1', [alarmInfo]);
