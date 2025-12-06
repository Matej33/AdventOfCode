package day_5;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class task1_5 {

    private long counter;
    private Long[][] ranges;

    public task1_5() {
        counter = 0;
        ranges = new Long[169][2];
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_5/input.txt");
        Scanner scanner = new Scanner(file);

        int i = 0;
        while (scanner.hasNextLine()) {
            String range = scanner.nextLine();
            if (range.trim().isEmpty()) {
                break;
            }
            String[] parts = range.split("-");
            ranges[i][0] = Long.parseLong(parts[0]);
            ranges[i][1] = Long.parseLong(parts[1]);
            i++;
        }
        while (scanner.hasNextLine()) {
            Long num = Long.parseLong(scanner.next());
            for (int j = 0; j < 169; j++) {
                if (num >= ranges[j][0] && num <= ranges[j][1]) {
                    counter++;
                    break;
                }
            }
        }
        System.out.println(counter);
    }
}
