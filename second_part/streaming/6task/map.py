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
    for w in words[1:]:
	print '%s\t%s' % (name, w.lower() + " " +  str (1))
