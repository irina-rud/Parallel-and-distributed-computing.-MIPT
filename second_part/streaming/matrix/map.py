#!/usr/bin/env python

import sys

for line in sys.stdin:
    name, data = line.split('\t')
    row, column, value = data.split(",") 
    N = int(sys.argv[1])
    M = int(sys.argv[2])
    if name == 'A':
        for i in range(N):
            print "%s.%s\t%s\t%s" % (row, i, column, value)
    elif name == 'B':
        for i in range(M):
            print "%s.%s\t%s\t%s" % (i, column, row, value)
