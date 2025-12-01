#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define db double
#define str string
#define vi vector<int>
#define pb push_back

class Visited {
public:
    int x, y;
    Visited(int x, int y) : x(x), y(y) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows = 4; // 140
    int cols = 4; // 140

    vector<vector<char>> grid(rows, vector<char>(cols));

    vector<Visited> visited;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    bool was;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = i+1; k < rows; k++) {
                for (int l = j+1; l < cols; l++) {
                    if (grid[i][j] == grid[k][l]) {

                    }
                }
            }
        }
    }



    return 0;
}