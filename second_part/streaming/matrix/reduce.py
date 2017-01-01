#!/usr/bin/env python

import sys

prev_row = None
prev_column = None
row = None
column = None
V = {}
item = 0

for line in sys.stdin:
    line.strip()
    if len(line) < 4:
        continue

    tokens, index, data = line.split('\t')
    row, column  =  tokens.split('.')
    try:
        data = int(data)
    except ValueError:
        continue
    
    if (prev_column == column) and (prev_row == row):
        if ( index in V.keys()):
            V[index].append(data)
        else:
            V[index] = [data]
    else:
        for i in V.keys():            
            item += V[i][0] * V[i][1]
        print "%s,%s\t%s" % (prev_row, prev_column, item)
        item = 0
        V = {}
        prev_row = row
        prev_column = column
        V[index] = [data]

if (prev_column == column) & (prev_row == row):
    for i in V.keys():
        item += V[i][0] * V[i][1]
    print "%s,%s\t%s" % (prev_row, prev_column, item)
