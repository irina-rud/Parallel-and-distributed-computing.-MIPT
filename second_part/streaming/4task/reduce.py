#!/usr/bin/env python

from operator import itemgetter
import sys

current_word = None
current_article = None
current_count = 0
word = None


for line in sys.stdin:
    line = line.strip()
    word, article, count = line.split('\t')

    try:
        count = int(count)
    except ValueError:
        continue

    if (current_word == word) & (current_article == article):
        current_count += count
    else:
        if current_word:
            if current_article:
                print '%s\t%s\t%s' % (current_word, current_article, current_count)
        current_count = count
        current_word = word
        current_article = article

if current_word :
     print '%s\t%s\t%s' % (current_word, current_article, current_count)
