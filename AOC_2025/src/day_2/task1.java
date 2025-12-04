package day_2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class task1 {

    private long counter;
    private long minFirstHalf;
    private long minSecondHalf;
    private long max;

    public task1() {
        counter = 0;
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_2/input.txt");
        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            String range = scanner.next();
            this.divide(range);
            while (((this.minFirstHalf * (long) Math.pow(10, String.valueOf(this.minSecondHalf).length())) + this.minSecondHalf) <= this.max) {
                if (this.minSecondHalf == this.minFirstHalf) {
                    this.counter += ((this.minFirstHalf * (long) Math.pow(10, String.valueOf(this.minSecondHalf).length())) + this.minSecondHalf);
                }
                this.increase();
            }
        }
        System.out.println(this.counter);
    }

    public void divide(String range) {
        String[] parts = range.split("-");
        String min = parts[0];
        this.max = Long.parseLong(parts[1]);
        long tempMin;

        if (min.length() % 2 != 0) {
            tempMin = (long) (1 * Math.pow(10, min.length() + 1));
            min = tempMin + "";
        }
        this.minFirstHalf = Long.parseLong(min.substring(0, min.length() / 2));
        this.minSecondHalf = Long.parseLong(min.substring(min.length() / 2));
    }

    public void increase() {
        if (this.minFirstHalf > this.minSecondHalf) {
            this.minSecondHalf = this.minFirstHalf;
        } else {
            this.minFirstHalf++;
            this.minSecondHalf = this.minFirstHalf;
        }
    }
}