#!/usr/bin/env python

from operator import itemgetter
import sys

current_word = None
current_name = None
pair = None
word = None
name = None
counter = 0

for line in sys.stdin:
    line = line.strip()
    
    name, word = line.split('\t')
    if current_name == name:
        if word != current_word:
            counter += 1
	    current_word = word            
    else:
        if current_name:
            print '%s\t%s' % (current_name,  str(counter))
        current_name = name
	counter = 0


if current_name:
    print '%s\t%s' % (current_name,  str(counter))


