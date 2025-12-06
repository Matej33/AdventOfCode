package day_5;

import java.io.File;
import java.io.InputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class task2_5 {

    private long counter;
    private List<Long[]> ranges;

    public task2_5() {
        counter = 0;
        this.ranges = new ArrayList<>();
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_5/input.txt");
        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            String range = scanner.nextLine();
            if (range.trim().isEmpty()) {
                break;
            }
            String[] parts = range.split("-");
            this.ranges.add(new Long[]{Long.parseLong(parts[0]), Long.parseLong(parts[1])});
        }

        this.sort();

        for (Long[] range : this.ranges) {
            counter += range[1] - range[0] + 1;
        }
        System.out.println(counter);

    }

    public void sort() {
        //int i - 1 = 0;
        this.ranges.sort(Comparator.comparingLong(o -> o[0]));
        while (true) {
            int size = this.ranges.size();
            for (int i = 1; i < this.ranges.size(); i++) {
                if (this.ranges.get(i)[0] <= this.ranges.get(i - 1)[1]) {
                    if (this.ranges.get(i)[0] >= this.ranges.get(i - 1)[0]){
                        if (this.ranges.get(i)[1] <= this.ranges.get(i - 1)[1]) {
                            this.ranges.remove(i);
                            this.sort();
                        } else {
                            this.ranges.set(i - 1, new Long[]{this.ranges.get(i - 1)[0], this.ranges.get(i)[1]});
                            this.ranges.remove(i);
                            this.sort();
                        }
                    } else if(this.ranges.get(i)[1] >= this.ranges.get(i - 1)[1]){
                        this.ranges.remove(i - 1);
                        this.sort();
                    } else if(this.ranges.get(i)[1] <= this.ranges.get(i - 1)[1] && this.ranges.get(i)[1] >= this.ranges.get(i - 1)[0]){
                        this.ranges.set(i - 1, new Long[]{this.ranges.get(i)[0], this.ranges.get(i - 1)[1]});
                        this.ranges.remove(i);
                        this.sort();
                    } else {
                        continue;
                    }
                } else {
                    continue;
                }
            }
            if (size == this.ranges.size()) {
                break;
            }
        }
    }
}