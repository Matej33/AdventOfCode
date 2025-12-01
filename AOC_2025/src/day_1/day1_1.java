package day_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class day1_1 {
    private int counter;
    private int index;

    public day1_1() {
        counter = 0;
        index = 50;
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_1/day_1.txt");
        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            boolean minus = false;
            String move = scanner.next();
            String direction = move.substring(0, 1);
            int num = Integer.parseInt(move.substring(1));
            if (direction.equals("R")) {
                this.index += num;
            } else {
                this.index -= num;
            }
            if (this.index < 0) {
                minus = true;
            }
            this.index = Math.abs(this.index);
            this.index %= 100;
            if (minus && this.index != 0) {
                this.index = 100 - this.index;
            }
            if (this.index == 0) {
                this.counter++;
            }
            if (scanner.hasNextLine()) {
                scanner.nextLine();
            }
        }
        scanner.close();
        System.out.println(this.counter);
    }
}
