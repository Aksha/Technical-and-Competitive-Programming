require 'influxdb'
require 'pg'
require 'byebug'

db = PG.connect(dbname: 'domo', user: 'akshaya', password: 'domo2018')
i = InfluxDB::Client.new 'telegraf', host: "bb246.target.com"


#throughput
q=i.query 'SELECT sum("ops") FROM "thalamus_production_broadcast" WHERE time >= now() - 7d GROUP BY time(1s) fill(none)'

#Num of tasks
show_tag_key_cardinality_stmt = i.query 'SHOW TAG VALUES FROM "thalamus_production_task_ingest" WITH KEY = "task"'


count = 0
#sizeofstmt = show_tag_key_cardinality_stmt[0]["values"].size()
show_tag_key_cardinality_stmt[0]["values"].each do |i|
	if(i["value"].start_with?("normal"))
		count += 1
	end
end

sum = 0
for i in q[0]["values"]
   sum += i["sum"]
end

db.prepare('statement1', 'insert into tasks_throughput_metrics (tasks,throughput) values ($1,$2)')
db.exec_prepared('statement1', [count, sum]);
