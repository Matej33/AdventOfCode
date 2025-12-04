package day_2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class task2_2 {

    private long counter;
    private String[] ranges;

    public task2_2() {
        this.counter = 0;
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_2/input.txt");
        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            String range = scanner.next();
            ranges = range.split("-");
            long first = Long.parseLong(ranges[0]);
            long max = Long.parseLong(ranges[1]);
            while (first <= max) {
                if (String.valueOf(first).length() == 6) {
                    boolean done = false;
                    String firstString = String.valueOf(first).substring(0, String.valueOf(first).length() / 2);
                    String secondString = String.valueOf(first).substring(String.valueOf(first).length() / 2);
                    if (Long.parseLong(firstString) == Long.parseLong(secondString)) {
                        this.counter += first;
                        done = true;
                    }
                    if (!done) {
                        String firstStringTwo = String.valueOf(first).substring(0, String.valueOf(first).length() / 3);
                        String secondStringTwo = String.valueOf(first).substring(String.valueOf(first).length() / 3, String.valueOf(first).length() / 3 * 2);
                        String thirdString = String.valueOf(first).substring(String.valueOf(first).length() / 3 * 2);
                        if (Long.parseLong(firstStringTwo) == Long.parseLong(secondStringTwo) && Long.parseLong(secondStringTwo) == Long.parseLong(thirdString)) {
                            this.counter += first;
                        }
                    }
                } else if (String.valueOf(first).length() == 10) {
                    boolean done = false;
                    String firstStringTwo = String.valueOf(first).substring(0, String.valueOf(first).length() / 2);
                    String secondStringTwo = String.valueOf(first).substring(String.valueOf(first).length() / 2);
                    if (Long.parseLong(firstStringTwo) == Long.parseLong(secondStringTwo)) {
                        this.counter += first;
                        done = true;
                    }
                    if (!done) {
                        String firstString = String.valueOf(first).substring(0, String.valueOf(first).length() / 5);
                        String secondString = String.valueOf(first).substring(String.valueOf(first).length() / 5, String.valueOf(first).length() / 5 * 2);
                        String thirdString = String.valueOf(first).substring(String.valueOf(first).length() / 5 * 2, String.valueOf(first).length() / 5 * 3);
                        String fourthString = String.valueOf(first).substring(String.valueOf(first).length() / 5 * 3, String.valueOf(first).length() / 5 * 4);
                        String fifthString = String.valueOf(first).substring(String.valueOf(first).length() / 5 * 4);
                        if (Long.parseLong(firstString) == Long.parseLong(secondString) && Long.parseLong(secondString) == Long.parseLong(thirdString) && Long.parseLong(thirdString) == Long.parseLong(fourthString) && Long.parseLong(fourthString) == Long.parseLong(fifthString)) {
                            this.counter += first;
                        }
                    }
                } else if (String.valueOf(first).length() % 2 == 0) {
                    String firstString = String.valueOf(first).substring(0, String.valueOf(first).length() / 2);
                    String secondString = String.valueOf(first).substring(String.valueOf(first).length() / 2);
                    if (Long.parseLong(firstString) == Long.parseLong(secondString)) {
                        this.counter += first;
                    }
                } else if (String.valueOf(first).length() % 3 == 0) {
                    String firstString = String.valueOf(first).substring(0, String.valueOf(first).length() / 3);
                    String secondString = String.valueOf(first).substring(String.valueOf(first).length() / 3, String.valueOf(first).length() / 3 * 2);
                    String thirdString = String.valueOf(first).substring(String.valueOf(first).length() / 3 * 2);
                    if (Long.parseLong(firstString) == Long.parseLong(secondString) && Long.parseLong(secondString) == Long.parseLong(thirdString)) {
                        this.counter += first;
                    }
                } else if (String.valueOf(first).length() % 5 == 0) {
                    String firstString = String.valueOf(first).substring(0, String.valueOf(first).length() / 5);
                    String secondString = String.valueOf(first).substring(String.valueOf(first).length() / 5, String.valueOf(first).length() / 5 * 2);
                    String thirdString = String.valueOf(first).substring(String.valueOf(first).length() / 5 * 2, String.valueOf(first).length() / 5 * 3);
                    String fourthString = String.valueOf(first).substring(String.valueOf(first).length() / 5 * 3, String.valueOf(first).length() / 5 * 4);
                    String fifthString = String.valueOf(first).substring(String.valueOf(first).length() / 5 * 4);
                    if (Long.parseLong(firstString) == Long.parseLong(secondString) && Long.parseLong(secondString) == Long.parseLong(thirdString) && Long.parseLong(thirdString) == Long.parseLong(fourthString) && Long.parseLong(fourthString) == Long.parseLong(fifthString)) {
                        this.counter += first;
                    }
                } else if (String.valueOf(first).length() % 7 == 0) {
                    String firstString = String.valueOf(first).substring(0, String.valueOf(first).length() / 7);
                    String secondString = String.valueOf(first).substring(String.valueOf(first).length() / 7, String.valueOf(first).length() / 7 * 2);
                    String thirdString = String.valueOf(first).substring(String.valueOf(first).length() / 7 * 2, String.valueOf(first).length() / 7 * 3);
                    String fourthString = String.valueOf(first).substring(String.valueOf(first).length() / 7 * 3, String.valueOf(first).length() / 7 * 4);
                    String fifthString = String.valueOf(first).substring(String.valueOf(first).length() / 7 * 4, String.valueOf(first).length() / 7 * 5);
                    String sixthString = String.valueOf(first).substring(String.valueOf(first).length() / 7 * 5, String.valueOf(first).length() / 7 * 6);
                    String seventhString = String.valueOf(first).substring(String.valueOf(first).length() / 7 * 6);
                    if (Long.parseLong(firstString) == Long.parseLong(secondString) && Long.parseLong(secondString) == Long.parseLong(thirdString) && Long.parseLong(thirdString) == Long.parseLong(fourthString) && Long.parseLong(fourthString) == Long.parseLong(fifthString) && Long.parseLong(fifthString) == Long.parseLong(sixthString) && Long.parseLong(sixthString) == Long.parseLong(seventhString)) {
                        this.counter += first;
                    }
                }
                first++;
            }
        }
        System.out.println(this.counter);
    }
}