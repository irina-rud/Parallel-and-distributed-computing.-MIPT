#!/usr/bin/env python

from operator import itemgetter
import sys

current_word = None
current_name = None
current_count = 0
pair = None
word = None
name = None
words = {}

for line in sys.stdin:
    line = line.strip()

    name, word = line.split('\t')
    word, count = word.split(' ')
    try:
        count = int(count)
    except ValueError:
        continue
    if current_name == name:
#        print word
 #       print words.keys()
        if word in words.keys():
            words[word] += count
        else:
            words[word] = count
    else:
        if current_name:
            for k in words.keys():
                print '%s\t%s' % (current_name, k + " " +  str(words[k]))
        current_name = name  


if current_name:
            for k in words.keys():
                print '%s\t%s' % (current_name, k +" " + str(words[k]))


