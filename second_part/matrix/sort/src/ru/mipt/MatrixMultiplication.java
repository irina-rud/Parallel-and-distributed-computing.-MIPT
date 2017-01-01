package ru.mipt;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

import java.io.IOException;
import java.lang.Integer;
import java.lang.String;
import java.util.*;

public class MatrixMultiplication {
    public final static int rows = 4;
    public final static int columns = 4;

    public static int main(String[] strings) throws Exception {
        Path outputPath = new Path(strings[1]);

        Job job1 = Job.getInstance();
        job1.setJarByClass(MatrixMultiplication.class);

        job1.setMapperClass(TaskMapper.class);
        job1.setReducerClass(TaskReducer.class);

        job1.setOutputKeyClass(Text.class);
        job1.setOutputValueClass(Text.class);

        job1.setInputFormatClass(TextInputFormat.class);
        job1.setOutputFormatClass(TextOutputFormat.class);

        job1.setMapOutputKeyClass(Text.class);
        job1.setMapOutputValueClass(Long.class);

        job1.setNumReduceTasks(2);

        TextInputFormat.addInputPath(job1, new Path(strings[0]));
        TextOutputFormat.setOutputPath(job1, outputPath);

        return job1.waitForCompletion(true)? 0: 1;
    }

    public static class TaskMapper extends Mapper<LongWritable, Text, Text, Text> {

        @Override
        public void map(LongWritable offset, Text aItem, Context context)
                throws IOException, InterruptedException {
            String[] splited = aItem.toString().split("\\t|\\s|,");
            if (splited[0].equals("A") || splited[0].equals("B")) {
                for (Integer i = 0; i < columns; ++i) {
                    context.write(new Text(splited[1] + "," + i.toString()), new Text(splited[2] + "," + splited[3]));
                }
            } else if (splited[0].equals("B")) {
                for (Integer i = 0; i < rows; ++i) {
                    context.write(new Text(i.toString() + "," + splited[2]), new Text(splited[2] + "," + splited[3]));
                }
            }

        }
    }

    public static class TaskReducer extends Reducer<Text, Text, Text, Text> {


        @Override
        protected void reduce(Text sell_index, Iterable<Text> pairs, Context context)
                throws IOException, InterruptedException {
            Iterator<Text> it = pairs.iterator();
            Long sell = 0L;

            Map<Integer, List<Integer>> multiplication = new HashMap<>();
            while (it.hasNext()) {
                String[] tokens = it.next().toString().split(",");
                Integer index = Integer.parseInt(tokens[0]);
                Integer value = Integer.parseInt(tokens[1]);
                if (multiplication.containsKey(index)) {
                    multiplication.get(index).add(value);
                } else {
                    multiplication.put(index, new ArrayList<Integer>(value));
                }
            }

            for (Integer index : multiplication.keySet()) {
                List<Integer> pair = multiplication.get(index);
                sell += pair.get(0) * pair.get(1);
            }

            context.write(sell_index, new Text(String.valueOf(sell)));
        }
    }
}
