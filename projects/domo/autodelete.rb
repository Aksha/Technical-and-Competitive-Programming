require 'pg'

db = PG.connect(dbname: 'domo', user: 'akshaya', password: 'domo')
db.prepare('statement1', 'truncate table metrics');
db.exec_prepared('statement1');
