package day_2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class task2 {

    private long counter;
    private String[] ranges;
    private Integer[] partsOfFirst;
    private Integer[] partsOfMax;

    public task2() {
        this.counter = 0;
    }

    public void loadFile() throws FileNotFoundException {
        File file = new File("./AOC_2025/src/day_2/input.txt");
        Scanner scanner = new Scanner(file);

        while (scanner.hasNextLine()) {
            String range = scanner.next();
            ranges = range.split("-");
            switch (ranges[0].length()) {

                case 2, 4, 8:
                    this.parse(ranges);
                    while (true) {
                        if ((this.partsOfFirst[0]) <= (this.partsOfMax[0])) {
                            if ((this.partsOfFirst[0]) >= (this.partsOfMax[0]) && (this.partsOfFirst[1]) > (this.partsOfMax[1])) {
                                break;
                            } else {
                                this.divide2();
                            }
                        } else {
                            break;
                        }
                    }
                    break;

                case 3, 9:
                    this.parse(ranges);
                    while (true) {
                        if ((this.partsOfFirst[0]) <= (this.partsOfMax[0])) {
                            if ((this.partsOfFirst[0]) >= (this.partsOfMax[0]) && (this.partsOfFirst[1]) > (this.partsOfMax[1]) && (this.partsOfFirst[2]) > (this.partsOfMax[2])) {
                                break;
                            } else {
                                this.divide3();
                            }
                        } else {
                            break;
                        }
                    }
                    break;

                case 5:
                    this.parse(ranges);
                    while (true) {
                        if ((this.partsOfFirst[0]) <= (this.partsOfMax[0])) {
                            if ((this.partsOfFirst[0]) >= (this.partsOfMax[0]) && (this.partsOfFirst[1]) > (this.partsOfMax[1]) && (this.partsOfFirst[2]) > (this.partsOfMax[2]) && (this.partsOfFirst[3]) > (this.partsOfMax[3]) && (this.partsOfFirst[4]) > (this.partsOfMax[4])) {
                                break;
                            } else {
                                this.divide5();
                            }
                        } else {
                            break;
                        }
                    }
                    break;
                case 6:
                    this.parse(ranges);
                    while (true) {
                        if ((this.partsOfFirst[0]) <= (this.partsOfMax[0])) {
                            if ((this.partsOfFirst[0]) >= (this.partsOfMax[0]) && (this.partsOfFirst[1]) > (this.partsOfMax[1])) {
                                break;
                            } else {
                                this.divide2();
                            }
                        } else {
                            break;
                        }
                    }
                    this.parse(ranges);
                    while (true) {
                        if ((this.partsOfFirst[0]) <= (this.partsOfMax[0])) {
                            if ((this.partsOfFirst[0]) >= (this.partsOfMax[0]) && (this.partsOfFirst[1]) > (this.partsOfMax[1]) && (this.partsOfFirst[2]) > (this.partsOfMax[2])) {
                                break;
                            } else {
                                this.divide3();
                            }
                        } else {
                            break;
                        }
                    }
                    break;
                case 7:
                    this.parse(ranges);
                    while (true) {
                        if ((this.partsOfFirst[0]) <= (this.partsOfMax[0])) {
                            if ((this.partsOfFirst[0]) >= (this.partsOfMax[0]) && (this.partsOfFirst[1]) > (this.partsOfMax[1]) && (this.partsOfFirst[2]) > (this.partsOfMax[2]) && (this.partsOfFirst[3]) > (this.partsOfMax[3]) && (this.partsOfFirst[4]) > (this.partsOfMax[4]) && (this.partsOfFirst[5]) > (this.partsOfMax[5]) && (this.partsOfFirst[6]) > (this.partsOfMax[6])) {
                                break;
                            } else {
                                this.divide7();
                            }
                        } else {
                            break;
                        }
                    }
                    break;
                case 10:
                    this.parse(ranges);
                    while (true) {
                        if ((this.partsOfFirst[0]) <= (this.partsOfMax[0])) {
                            if ((this.partsOfFirst[0]) >= (this.partsOfMax[0]) && (this.partsOfFirst[1]) > (this.partsOfMax[1])) {
                                break;
                            } else {
                                this.divide2();
                            }
                        } else {
                            break;
                        }
                    }
                    this.parse(ranges);
                    while (true) {
                        if ((this.partsOfFirst[0]) <= (this.partsOfMax[0])) {
                            if ((this.partsOfFirst[0]) >= (this.partsOfMax[0]) && (this.partsOfFirst[1]) > (this.partsOfMax[1]) && (this.partsOfFirst[2]) > (this.partsOfMax[2]) && (this.partsOfFirst[3]) > (this.partsOfMax[3]) && (this.partsOfFirst[4]) > (this.partsOfMax[4])) {
                                break;
                            } else {
                                this.divide5();
                            }
                        } else {
                            break;
                        }
                    }
                    break;
            }
        }
        System.out.println(this.counter);
    }

    public void parse(String ranges[]) {
        this.partsOfFirst = new Integer[ranges[0].length()];
        this.partsOfMax = new Integer[ranges[0].length()];
        for (int i = 0; i < ranges[0].length(); i++) {
            this.partsOfFirst[i] = ranges[0].substring(i, i + 1).toString().charAt(0) - '0';
            this.partsOfMax[i] = ranges[1].substring(i, i + 1).toString().charAt(0) - '0';
        }
    }

    public void divide2() { //TODO tie co nie su prvocisla nefunguju
        if (this.partsOfFirst[0].equals(this.partsOfFirst[1])) {
            this.counter += (this.partsOfFirst[0]) * 10 + (this.partsOfFirst[1]);
        }
        if ((this.partsOfFirst[0]) <= (this.partsOfFirst[1])) {
            this.partsOfFirst[0]++;
            this.partsOfFirst[1]++;
        } else {
            this.partsOfFirst[1]++;
        }
    }

    public void divide3() {
        if (this.partsOfFirst[0].equals(this.partsOfFirst[1]) && this.partsOfFirst[2].equals(this.partsOfFirst[1])) {
            this.counter += (this.partsOfFirst[0]) * 100 + (this.partsOfFirst[1]) * 10 + (this.partsOfFirst[2]);
            this.partsOfFirst[0]++;
        }
        if ((this.partsOfFirst[0]) < (this.partsOfFirst[1]) || (this.partsOfFirst[0]) < (this.partsOfFirst[2])) {
            this.partsOfFirst[0]++;
        } else {
            this.partsOfFirst[2] = this.partsOfFirst[0];
            this.partsOfFirst[1] = this.partsOfFirst[0];
        }
    }

    public void divide5() {
        if (this.partsOfFirst[0].equals(this.partsOfFirst[1]) && this.partsOfFirst[2].equals(this.partsOfFirst[1]) && this.partsOfFirst[3].equals(this.partsOfFirst[1]) && this.partsOfFirst[4].equals(this.partsOfFirst[1])) {
            this.counter += (this.partsOfFirst[0]) * 10000 + (this.partsOfFirst[1]) * 1000 + (this.partsOfFirst[2]) * 100 + (this.partsOfFirst[3]) * 10 + (this.partsOfFirst[4]);
            this.partsOfFirst[0]++;
        }
        if ((this.partsOfFirst[0]) < (this.partsOfFirst[1]) || (this.partsOfFirst[0]) < (this.partsOfFirst[2]) || (this.partsOfFirst[0]) < (this.partsOfFirst[3]) || (this.partsOfFirst[0]) < (this.partsOfFirst[4])) {
            this.partsOfFirst[0]++;
        } else {
            this.partsOfFirst[4] = this.partsOfFirst[0];
            this.partsOfFirst[3] = this.partsOfFirst[0];
            this.partsOfFirst[2] = this.partsOfFirst[0];
            this.partsOfFirst[1] = this.partsOfFirst[0];
        }
    }

    public void divide7() {
        if (this.partsOfFirst[0].equals(this.partsOfFirst[1]) && this.partsOfFirst[2].equals(this.partsOfFirst[1]) && this.partsOfFirst[3].equals(this.partsOfFirst[1]) && this.partsOfFirst[4].equals(this.partsOfFirst[1]) && this.partsOfFirst[5].equals(this.partsOfFirst[1]) && this.partsOfFirst[6].equals(this.partsOfFirst[1])) {
            this.counter += (this.partsOfFirst[0]) * 1000000 + (this.partsOfFirst[1]) * 100000 + (this.partsOfFirst[2]) * 10000 + (this.partsOfFirst[3]) * 1000 + (this.partsOfFirst[4]) * 100 + (this.partsOfFirst[5]) * 10 + (this.partsOfFirst[6]);
        }
        if ((this.partsOfFirst[0]) < (this.partsOfFirst[1]) || (this.partsOfFirst[0]) < (this.partsOfFirst[2]) || (this.partsOfFirst[0]) < (this.partsOfFirst[3]) || (this.partsOfFirst[0]) < (this.partsOfFirst[4]) || (this.partsOfFirst[0]) < (this.partsOfFirst[5]) || (this.partsOfFirst[0]) < (this.partsOfFirst[6])) {
            this.partsOfFirst[0]++;
        } else {
            this.partsOfFirst[6] = this.partsOfFirst[0];
            this.partsOfFirst[5] = this.partsOfFirst[0];
            this.partsOfFirst[4] = this.partsOfFirst[0];
            this.partsOfFirst[3] = this.partsOfFirst[0];
            this.partsOfFirst[2] = this.partsOfFirst[0];
            this.partsOfFirst[1] = this.partsOfFirst[0];
        }
    }

}