#!/usr/bin/env python

import sys
import re


for line in sys.stdin:
    line = line.strip()
    name  = line.split('\t')[0]
    words = re.findall(r'\w+',line)
    for word in words:
        if word:
            print '%s\t%s\t%s' % (word.lower(), name, 1)

