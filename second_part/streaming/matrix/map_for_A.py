#!/usr/bin/env python

import sys

for line in sys.stdin:
    print "A\t" + line[:-1]
