package day_4;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class task2_4 {
    private int counter;
    private Character[][] board;
    private List<Character> toiletteRolls;

    public task2_4() {
        this.counter = 0;
        this.board = new Character[138][138];
        this.toiletteRolls = Arrays.asList('x', '@');
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_4/input.txt");
        Scanner scanner = new Scanner(file);

        int i = 0;
        while (scanner.hasNextLine()) {
            String num = scanner.next();
            for (int j = 0; j < 138; j++) {
                this.board[i][j] = num.charAt(j);
            }
            i++;
        }
        this.check();
        System.out.println(this.counter);
        scanner.close();
    }

    public void check() {
        int previous = counter;
        for (int i = 0; i < 138; i++) {
            for (int j = 0; j < 138; j++) {
                if (this.board[i][j] == '.') continue;
                if (this.board[i][j] == '@') {
                    int neighborhoods = 0;
                    if (i > 0 && this.toiletteRolls.contains(board[i - 1][j])) neighborhoods++;
                    if (i < 138 - 1 && this.toiletteRolls.contains(board[i + 1][j])) neighborhoods++;
                    if (j > 0 && this.toiletteRolls.contains(board[i][j - 1])) neighborhoods++;
                    if (j < 138 - 1 && this.toiletteRolls.contains(board[i][j + 1])) neighborhoods++;
                    if (j > 0 && i > 0 && this.toiletteRolls.contains(board[i - 1][j - 1])) neighborhoods++;
                    if (j < 138 - 1 && i > 0 && this.toiletteRolls.contains(board[i - 1][j + 1])) neighborhoods++;
                    if (j > 0 && i < 138 - 1 && this.toiletteRolls.contains(board[i + 1][j - 1])) neighborhoods++;
                    if (j < 138 - 1 && i < 138 - 1 && this.toiletteRolls.contains(board[i + 1][j + 1])) neighborhoods++;
                    if (neighborhoods < 4) {
                        this.counter++;
                        this.board[i][j] = 'x';
                    }
                }
            }
        }
        for (int i = 0; i < 138; i++) {
            for (int j = 0; j < 138; j++) {
                if (this.board[i][j] == 'x') {
                    this.board[i][j] = '.';
                }
            }
        }
        if (previous != this.counter) {
            System.out.println(this.counter);
            this.check();
        }
    }

}
