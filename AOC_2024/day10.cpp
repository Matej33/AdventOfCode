#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define db double
#define str string
#define vi vector<ll>
#define pb push_back
#define eb emplace_back

class Visited {
public:
    int x, y;

    Visited(int x, int y) : x(x), y(y) {}
};

bool way() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows = 8;
    int cols = 8;
    int posX, posY;

    vector<vector<int>> grid(rows, vector<int>(cols));
    vector<Visited> visited;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(grid[i][j] == 9) {
                if(grid[i][j+1] == 8 || grid[i][j-1] == 8 || grid[i+1][j] == 8 || grid[i-1][j] == 8) {
                    if(grid[i][j+1] == 8) {
                        bool alreadyVisited = false;
                        for (int k = 0; k < visited.size(); k++) {
                            if(visited[k].x == i && visited[k].y == j+1) {
                                alreadyVisited = true;
                                break;
                            }
                        }
                        if (!alreadyVisited) {
                            posX = i;
                            posY = j+1;
                            visited.eb(posX, posY);
                        }
                    } else if(grid[i][j-1] == 8) {
                        bool alreadyVisited = false;
                        for (int k = 0; k < visited.size(); k++) {
                            if(visited[k].x == i && visited[k].y == j-1) {
                                alreadyVisited = true;
                                break;
                            }
                        }
                        if (!alreadyVisited) {
                            posX = i;
                            posY = j-1;
                            visited.eb(posX, posY);
                        }
                    } else if(grid[i+1][j] == 8) {
                        bool alreadyVisited = false;
                        for (int k = 0; k < visited.size(); k++) {
                            if(visited[k].x == i+1 && visited[k].y == j) {
                                alreadyVisited = true;
                                break;
                            }
                        }
                        if (!alreadyVisited) {
                            posX = i+1;
                            posY = j;
                            visited.eb(posX, posY);
                        }
                    } else if(grid[i-1][j] == 8) {
                        bool alreadyVisited = false;
                        for (int k = 0; k < visited.size(); k++) {
                            if(visited[k].x == i-1 && visited[k].y == j) {
                                alreadyVisited = true;
                                break;
                            }
                        }
                        if (!alreadyVisited) {
                            posX = i-1;
                            posY = j;
                            visited.eb(posX, posY);
                        }
                    }
                    if (grid[posX][posY+1] == 7 || grid[posX][posY-1] == 7 || grid[posX+1][posY] == 7 || grid[posX-1][posY] == 7){
                        //to co pre 8 treba az po 0
                    }
                }
            }
        }
    }

    return 0;
}