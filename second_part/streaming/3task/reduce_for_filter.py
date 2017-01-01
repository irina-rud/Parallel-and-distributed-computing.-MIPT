#!/usr/bin/env python

from operator import itemgetter
import sys


prev_lower_word = None
word = None


for line in sys.stdin:
    line = line.strip()
    word_lower, word, count = line.split('\t')

    if word.lower() == word:
        prev_lower_word = word
    else:
        if  (word.lower() != prev_lower_word):
            print '%s\t%s' % (word, count)

if (word.lower() !=prev_lower_word) & (word.lower != word):
    print '%s\t%s' % (word, count)
