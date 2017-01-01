#!/usr/bin/env python

import sys
import string
import re
import codecs

#UTF8Reader = codecs.getreader('cp1251')
#sys.stdin = UTF8Reader(sys.stdin)
for line in sys.stdin:
 #   print(line)
    words = re.split(r"[ \n\t.,!?:;]+", line)
    name = words[0]
    print name
    name_copy = name
    name_copy = name_copy.lower()
    print name_copy
    if name_copy != name :
        for w in words[1:]:
	    if w:
                print '%s\t%s' % (name, w.lower())

