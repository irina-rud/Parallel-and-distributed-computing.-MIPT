package ru.mipt;

import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.util.Tool;

import java.io.IOException;
import java.lang.Integer;
import java.lang.String;
import java.lang.StringBuilder;
import java.util.Iterator;


public class IndexCount extends Configured implements Tool{

    public static class WordMapper extends Mapper<LongWritable, Text, Text, IntWritable>{
        private Text word = new Text();

        public void map(LongWritable offset, Text line, Context context) throws IOException, InterruptedException {

            String[] words = line.toString().split("\\W+");

            Integer id = Integer.parseInt(words[0]);

            IntWritable fileId = new IntWritable(id);

            for(int i = 1; i < words.length; ++i){
                word.set(words[i]);
                context.write(word, fileId);
            }
        }
    }

    public static class IndexReducer extends Reducer<Text, IntWritable, Text, Text>{
        private Text index = new Text();

        public void reduce(Text word, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
            Iterator<IntWritable> it = values.iterator();
            StringBuilder indexForWorld = new StringBuilder();
            while (it.hasNext()){
                indexForWorld.append(new String("  "));
                indexForWorld.append((new Integer(it.next().get())).toString());
            }
            index.set(indexForWorld.toString());
            context.write(word, index);
        }
    }

    @Override
    public int run(String[] strings) throws Exception {
        Path outputPath = new Path(strings[1]);

        Job job1 = Job.getInstance();
        job1.setJarByClass(IndexCount.class);

        job1.setMapperClass(WordMapper.class);
        job1.setReducerClass(IndexReducer.class);

        job1.setOutputKeyClass(Text.class);
        job1.setOutputValueClass(Text.class);

        job1.setInputFormatClass(TextInputFormat.class);
        job1.setOutputFormatClass(TextOutputFormat.class);

        job1.setMapOutputKeyClass(Text.class);
        job1.setMapOutputValueClass(IntWritable.class);

        job1.setNumReduceTasks(8);

        TextInputFormat.addInputPath(job1, new Path(strings[0]));
        TextOutputFormat.setOutputPath(job1, outputPath);

        return job1.waitForCompletion(true)? 0: 1;
    }

    public static void main(String[] args) throws Exception {
        new IndexCount().run(args);
    }
}

