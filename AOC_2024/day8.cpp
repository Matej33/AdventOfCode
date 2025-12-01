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

class Hashtag {
public:
    int x, y;

    Hashtag(int x, int y) : x(x), y(y) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows = 50; // 50
    int cols = 50; // 50

    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    bool idk = true;
    char znak;
    int x, y, posX, posY, times = 1;
    vector<char> bolo;
    vector<Hashtag> hashtagy;
    hashtagy.eb(99, 99);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] != '.') {
                bolo.pb(grid[i][j]);
                znak = grid[i][j];
                for (int k = 0; k < rows; k++) {
                    for (int l = 0; l < cols; l++) {
                        if (grid[k][l] == znak && (i != k && j != l)) {
                            x = i - k;
                            y = j - l;
                            while (posX >= 0 && posX < rows && posY >= 0 && posY < cols) {
                                posX = ((x * times) + i);
                                posY = ((y * times) + j);
                                times++;
                                if (posX >= 0 && posX < rows && posY >= 0 && posY < cols) {
                                    for (int m = 0; m < hashtagy.size(); m++) {
                                        if (hashtagy[m].x == posX && hashtagy[m].y == posY) {
                                            idk = false;
                                        }
                                    }
                                    if (idk && grid[posX][posY] == '.') {
                                        hashtagy.eb(posX, posY);
                                    }
                                    idk = true;
                                }
                            }
                            times = 1;
                            x = k - i;
                            y = l - j;
                            posX = x * times + k;
                            posY = y * times + l;
                            while (posX >= 0 && posX < rows && posY >= 0 && posY < cols) {
                                posX = x * times + k;
                                posY = y * times + l;
                                times++;
                                if (posX >= 0 && posX < rows && posY >= 0 && posY < cols) {
                                    for (int m = 0; m < hashtagy.size(); m++) {
                                        if (hashtagy[m].x == posX && hashtagy[m].y == posY) {
                                            idk = false;
                                        }
                                    }
                                    if (idk && grid[posX][posY] == '.') {
                                        hashtagy.eb(posX, posY);
                                    }
                                    idk = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << (hashtagy.size() - 1) + bolo.size() << endl;

    return 0;
}

/*
 * part 1
 class Hashtag {
public:
    int x, y;

    Hashtag(int x, int y) : x(x), y(y) {}
};

 int rows = 50; // 50
    int cols = 50; // 50
    vector<vector<char>> grid(rows, vector<char>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }
    bool idk = true;
    char znak;
    int x, y, posX, posY;
    vector<Hashtag> hashtagy;
    hashtagy.eb(15, 15);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] != '.') {
                znak = grid[i][j];
                for (int k = 0; k < rows; k++) {
                    for (int l = 0; l < cols; l++) {
                        if (grid[k][l] == znak && (i != k && j != l)) {
                            x = i - k;
                            y = j - l;
                            posX = x + i;
                            posY = y + j;
                            if (posX >= 0 && posX < rows && posY >= 0 && posY < cols) {
                                for (int m = 0; m < hashtagy.size(); m++) {
                                    if (hashtagy[m].x == posX && hashtagy[m].y == posY) {
                                        idk = false;
                                    }
                                }
                                if (idk) {
                                    hashtagy.eb(posX, posY);
                                }
                                idk = true;
                            }
                            x = k - i;
                            y = l - j;
                            posX = x + k;
                            posY = y + l;
                            if (posX >= 0 && posX < rows && posY >= 0 && posY < cols) {
                                for (int m = 0; m < hashtagy.size(); m++) {
                                    if (hashtagy[m].x == posX && hashtagy[m].y == posY) {
                                        idk = false;
                                    }
                                }
                                if (idk) {
                                    hashtagy.eb(posX, posY);
                                }
                                idk = true;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << (hashtagy.size() - 1) << endl;
 */