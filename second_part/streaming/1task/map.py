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
            if (word[0] == 'I') | (word[0] == 'i'):
                print '%s\t%s' % (word.lower(), 1)

