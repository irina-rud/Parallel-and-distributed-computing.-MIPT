#!/usr/bin/env python

from operator import itemgetter
import sys

current_word = None
current_article = None
current_count = 0
index = ""
word = None


for line in sys.stdin:
    line = line.strip()
    if line:
        line = line.strip()
        word, article, count = line.split('\t')

        if current_word == word:
            index += ' %s(%s)' % (article, count)
        else:
            if current_word:
		if index != "":
                    print '%s\t%s' % (current_word, index)
            index = ""
            current_word = word


if current_word == word:
    print '%s\t%s' % (current_word, index)            
