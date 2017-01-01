#!/usr/bin/env python

from operator import itemgetter
import sys

current_word = None
current_article = None
current_count = 0
word = None


for line in sys.stdin:
    line = line.strip()
    word, article = line.split('\t')

    if (current_word == word) & (current_article != article):
        current_count += 1
        current_article = article
    elif (current_word != word):
        if current_word:
            if current_article:
                print '%s\t%s' % (current_word, current_count)
        current_count = 1
        current_word = word
        current_article = article

if current_word :
     print '%s\t%s' % (current_word, current_count)
