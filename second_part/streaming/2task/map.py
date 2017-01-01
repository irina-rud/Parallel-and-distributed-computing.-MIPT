#!/usr/bin/env python

import sys
import re


for line in sys.stdin:
    # remove leading and trailing whitespace
    line = line.strip()
    # split the line into words
    words = re.findall(r'\w+',line)
    for word in words:
        if word:
            if (len(word) > 5) & (len(word) < 10):
                print '%s\t%s' % (word.lower(), 1)

