import json
f1 = open(r'/Users/aravichandran/Desktop/all/jira tickets/CAT-1888/brands.json')
brands = f1.read()
brand_d = json.loads(brands)
bd = {}

for item in brand_d:
    bd[item['brand_id']] = item['name']

f1.close()