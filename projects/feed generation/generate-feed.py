f3 = open('/Users/aravichandran/Desktop/all/jira tickets/CAT-1888/retailers.csv', 'r')
rd = {}
for line in f3:
    key, val = line.split(',')[0], ','.join(line.split(',')[1:])
    rd[key] = val.strip('\n')
f3.close()

import csv

brand_d = csv.reader(open('/Users/aravichandran/Desktop/all/jira tickets/CAT-1888/brands.csv'))
bd = {}   
result = {}
for row in brand_d:
    key = row[0]
    bd[key] = row[1]
    
def computeListId(d):
    res = []
    image_url = d['i']['p']['u'] if 'i' in d and 'p' in d['i'] and 'iu' in d['i']['p'] else ''
    idd = d['_id']
    if 'inv' in d:
        for invariant in d['inv']:
            fpid = invariant['fplid'] if 'fplid' in invariant else None
            c, s = None, None
            if 'c' in invariant:
                c = invariant['c']
            if 's' in invariant:
                s = invariant['s']
            color, size, url = '', '', ''
            if c!= None and c >= 0:
                color = d['co'][c]['n']
                url = d['co'][c]['p']['iu'] if 'p' in d['co'][c] else image_url
            if (s != None and s >= 0) and s < len(d['ps']):
                size = d['ps'][s]['n']
            res.append(("%d_%s" % (idd, color) if fpid == None else fpid, url))    
    else:
        res.append((idd, image_url))
    
    return res

from xml.etree.ElementTree import Element, SubElement, tostring
import xml.dom.minidom
import re
import datetime
import json
import sys
reload(sys)
sys.setdefaultencoding('utf8')


fields = {"_"}
root = Element('feed')
child = SubElement(root, 'title')
child.text = 'test'
child1 = SubElement(root, 'update')
dt = str(datetime.datetime.now())
startText = '<?xml version="1.0" encoding="UTF-8" ?><feed xmlns="http://www.w3.org/2005/Atom" xmlns:g="http://base.google.com/ns/1.0"><title>ShopStyle en_US Syte product feed</title><updated>%s</updated>'%(dt)

def addEntry(node, d, pid, image_link):
    SubElement(node, 'id').text = pid
    SubElement(node, 'image_link').text = image_link
    SubElement(node, 'title').text = d['n'] if 'n' in d else ''
    SubElement(node, 'description').text = str(d['d']) if 'd' in d else ''
    SubElement(node, 'category_tags').text = str(d['ct']) if 'ct' in d else ''
    SubElement(node, 'retailer_categories').text = str(d['rc']) if 'rc' in d else ''
    SubElement(node, 'brand').text = str(bd[int(d['bid'])]) if 'bid' in d and int(d['bid']) in bd else ''
    SubElement(node, 'custom_label_0').text = rd[str(d['rid'])] if 'rid' in d and str(d['rid']) in rd else None

with open(r'/Users/aravichandran/Desktop/all/jira tickets/CAT-1888/test1', 'r') as fin:
    with open(r'/Users/aravichandran/Desktop/all/jira tickets/CAT-1888/syte_retired_feed.xml', 'w') as fout:
        fout.write(startText)
        i = 0
        for line in fin:
            d = json.loads(re.sub(r'NumberLong\((\d+)\)', r'\1', line))
            vals = computeListId(d)
            for val in vals:
                i += 1
                pid, imUrl = val
                entryNode = Element('entry')
                if not (imUrl == None or imUrl == ''):
                    addEntry(entryNode, d, str(pid).strip('_'), imUrl)
                    fout.write(str(tostring(entryNode)).strip('"').replace('b"', '') + '\n')
                if (i %100000 == 0):
                    print(i)
                if i == 10000000:
                    break
            if i == 10000000:
                break
        fout.write('</feed>')
