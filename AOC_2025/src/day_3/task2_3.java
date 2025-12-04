package day_3;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class task2_3 {
    private long counter;
    private BigInteger counter2;
    private String num;

    public task2_3() {
        this.counter = 0;
        this.counter2 = new BigInteger("0");
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_3/input.txt");
        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            this.num = scanner.next();
            this.pls();
            this.num = this.num.substring(0, 12);
            System.out.println(this.num);
            this.counter += Long.parseLong(num);
            this.counter2 = counter2.add(new BigInteger(num));
            System.out.println("adding " + num);
        }
        System.out.println(counter);
        System.out.println(counter2);
    }

    public void pls() {
        for (int i = 0; i < this.num.length() - 1; i++) {
            if (Integer.parseInt(String.valueOf(this.num.charAt(i))) < Integer.parseInt(String.valueOf(this.num.charAt(i + 1)))) {
                if (this.num.length() > 12) {
                    StringBuilder sb = new StringBuilder(this.num);
                    sb.deleteCharAt(i);
                    this.num = sb.toString();
                    this.pls();
                }
            }
        }
    }
}
