#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define db double
#define str string
#define vi vector<int>
#define pb push_back
#define eb emplace_back

class Visited {
public:
    int x, y;
    char direction;

    Visited(int x, int y, char direction) : x(x), y(y), direction(direction) {}
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows = 130; // 130
    int cols = 130; // 130

    int posX = 0, posY = 0, counter = 0, xpos, ypos;
    char guard, guardpos;
    bool guardIn = true;
    vector<Visited> visited;
    vector<vector<char>> grid(rows, vector<char>(cols));
    vector<vector<char>> normalGrid(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '^') {
                xpos = j;
                ypos = i;
                posX = j;
                posY = i;
                guardpos = grid[i][j];
                guard = grid[i][j];
            }
        }
    }
    normalGrid = grid;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '.') {
                grid[i][j] = '#';
            }
            while (guardIn) {


                if (guard == '^') {
                    if (posY > 0 && (grid[posY - 1][posX] == '.' || grid[posY - 1][posX] == 'X')) {
                        if (grid[posY - 1][posX] == '.') {
                            grid[posY][posX] = 'X';
                            visited.eb(posX, posY, guard);
                            posY--;
                        } else if (grid[posY - 1][posX] == 'X') {
                            for (int k = 0; k < visited.size(); k++) {
                                if (visited[k].x == posX && visited[k].y == posY && visited[k].direction == guard) {
                                    counter++;
                                    guardIn = false;
                                    break;
                                }
                            }
                            grid[posY][posX] = 'X';
                            visited.eb(posX, posY, guard);
                            posY--;
                        }
                    } else if (posY > 0 && grid[posY - 1][posX] == '#') {
                        guard = '>';
                    } else {
                        guardIn = false;
                    }


                } else if (guard == '>') {
                    if (posX < cols - 1 && (grid[posY][posX + 1] == '.' || grid[posY][posX + 1] == 'X')) {
                        if (grid[posY][posX + 1] == '.') {
                            grid[posY][posX] = 'X';
                            visited.eb(posX, posY, guard);
                            posX++;
                        } else if (grid[posY][posX + 1] == 'X') {
                            for (int k = 0; k < visited.size(); k++) {
                                if (visited[k].x == posX && visited[k].y == posY && visited[k].direction == guard) {
                                    counter++;
                                    guardIn = false;
                                    break;
                                }
                            }
                            grid[posY][posX] = 'X';
                            visited.eb(posX, posY, guard);
                            posX++;
                        }
                    } else if (posX < cols - 1 && grid[posY][posX + 1] == '#') {
                        guard = 'v';
                    } else {
                        guardIn = false;
                    }


                } else if (guard == 'v') {
                    if (posY < rows - 1 && (grid[posY + 1][posX] == '.' || grid[posY + 1][posX] == 'X')) {
                        if (grid[posY + 1][posX] == '.') {
                            grid[posY][posX] = 'X';
                            visited.eb(posX, posY, guard);
                            posY++;
                        } else if (grid[posY + 1][posX] == 'X') {
                            for (int k = 0; k < visited.size(); k++) {
                                if (visited[k].x == posX && visited[k].y == posY && visited[k].direction == guard) {
                                    counter++;
                                    guardIn = false;
                                    break;
                                }
                            }
                            grid[posY][posX] = 'X';
                            visited.eb(posX, posY, guard);
                            posY++;
                        }
                    } else if (posY < rows - 1 && grid[posY + 1][posX] == '#') {
                        guard = '<';
                    } else {
                        guardIn = false;
                    }


                } else if (guard == '<') {
                    if (posX > 0 && (grid[posY][posX - 1] == '.' || grid[posY][posX - 1] == 'X')) {
                        if (grid[posY][posX - 1] == '.') {
                            grid[posY][posX] = 'X';
                            visited.eb(posX, posY, guard);
                            posX--;
                        } else if (grid[posY][posX - 1] == 'X') {
                            for (int k = 0; k < visited.size(); k++) {
                                if (visited[k].x == posX && visited[k].y == posY && visited[k].direction == guard) {
                                    counter++;
                                    guardIn = false;
                                    break;
                                }
                            }
                            grid[posY][posX] = 'X';
                            visited.eb(posX, posY, guard);
                            posX--;
                        }
                    } else if (posX > 0 && grid[posY][posX - 1] == '#') {
                        guard = '^';
                    } else {
                        guardIn = false;
                    }
                } else {
                    guardIn = false;
                }
            }
            /*for (int k = 0; k < rows; k++) {
                for (int l = 0; l < cols; l++) {
                    cout << grid[k][l];
                }
                cout << endl;
            }
            cout << "----------------" << endl;*/
            grid = normalGrid;
            guardIn = true;
            posX = xpos;
            posY = ypos;
            guard = guardpos;
            visited.clear();
        }
    }

    cout << counter << endl;

    return 0;
}


/*
 * part 1
 int rows = 130; // 130
    int cols = 130; // 130

    int posX = 0, posY = 0, counter = 1;
    char guard;

    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '^') {
                posX = j;
                posY = i;
                guard = grid[i][j];
            }
        }
    }

    bool guardIn = true;

    while (guardIn) {
        if (guard == '^') {
            if (posY > 0 && (grid[posY - 1][posX] == '.' || grid[posY - 1][posX] == 'X')) {
                if (grid[posY - 1][posX] == '.') {
                    counter++;
                }
                grid[posY][posX] = 'X';
                posY--;
            } else if (posY > 0 && grid[posY - 1][posX] == '#') {
                guard = '>';
            } else {
                guardIn = false;
            }

        } else if (guard == '>') {
            if (posX < cols - 1 && (grid[posY][posX + 1] == '.' || grid[posY][posX + 1] == 'X')) {
                if (grid[posY][posX + 1] == '.') {
                    counter++;
                }
                grid[posY][posX] = 'X';
                posX++;
            } else if (posX < cols - 1 && grid[posY][posX + 1] == '#') {
                guard = 'v';
            } else {
                guardIn = false;
            }
        } else if (guard == 'v') {
            if (posY < rows - 1 && (grid[posY + 1][posX] == '.' || grid[posY + 1][posX] == 'X')) {
                if (grid[posY + 1][posX] == '.') {
                    counter++;
                }
                grid[posY][posX] = 'X';
                posY++;
            } else if (posY < rows - 1 && grid[posY + 1][posX] == '#') {
                guard = '<';
            } else {
                guardIn = false;
            }
        } else if (guard == '<') {
            if (posX > 0 && (grid[posY][posX - 1] == '.' || grid[posY][posX - 1] == 'X')) {
                if (grid[posY][posX - 1] == '.') {
                    counter++;
                }
                grid[posY][posX] = 'X';
                posX--;
            } else if (posX > 0 && grid[posY][posX - 1] == '#') {
                guard = '^';
            } else {
                guardIn = false;
            }
        } else {
            guardIn = false;
        }
    }

    cout << counter << endl;
 */