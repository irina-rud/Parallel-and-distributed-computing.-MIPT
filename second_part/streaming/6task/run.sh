#!/bin/bash  
hdfs dfs -rm -r goreRes


hadoop jar /opt/cloudera/parcels/CDH-5.9.0-1.cdh5.9.0.p0.23/lib/hadoop-mapreduce/hadoop-streaming.jar \
-file map.py    -mapper map.py \
-file reduce.py   -reducer reduce.py \
-input /data/griboedov -output goreRes

hdfs dfs -ls goreRes
