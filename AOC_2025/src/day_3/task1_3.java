package day_3;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class task1_3 {
    private int counter;

    public task1_3() {
        counter = 0;
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_3/input.txt");
        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            String num = scanner.next();
            int max10 = 0;
            int index10 = 0;
            int max1 = 0;
            for (int i = 0; i < num.length() - 1; i++) {
                if (Integer.parseInt(String.valueOf(num.charAt(i))) > max10) {
                    max10 = Integer.parseInt(String.valueOf(num.charAt(i)));
                    index10 = i;
                }
            }
            for (int i = index10 + 1; i < num.length(); i++) {
                if (Integer.parseInt(String.valueOf(num.charAt(i))) > max1) {
                    max1 = Integer.parseInt(String.valueOf(num.charAt(i)));
                }
            }
            this.counter += max10 * 10 + max1;
        }
        System.out.println(this.counter);
    }
}
