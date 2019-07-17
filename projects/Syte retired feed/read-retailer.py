f3 = open('/Users/aravichandran/Desktop/all/jira tickets/CAT-1888/retailers.csv', 'r')
rd = {}
for line in f3:
    key, val = line.split(',')[0], ','.join(line.split(',')[1:])
    rd[key] = val.strip('\n')
f3.close()