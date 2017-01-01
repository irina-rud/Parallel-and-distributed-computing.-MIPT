#!/usr/bin/env python

import sys
import re
# good idea, but we can't install new libs 
# from nltk.tag import pos_tag

for line in sys.stdin:
   
    line = line.strip()
    # using nltk 
    # tagged_sent = pos_tag(re.findall(r'\w+',line))
    # words = [word for word,pos in tagged_sent if pos == 'NNP']
    words  = re.findall(r'\w+',line)

    for word in words:
        if word:
            print '%s\t%s\t%s' % (word.lower(), word, 1)

