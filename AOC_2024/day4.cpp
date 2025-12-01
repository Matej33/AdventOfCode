#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define db double
#define str string
#define vi vector<int>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows = 140; // 140
    int cols = 140; // 140

    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    int counter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'A' && i - 1 >= 0 && j - 1 >= 0 && i + 1 < rows && j + 1 < cols) {
                if (grid[i - 1][j - 1] == 'M' && grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'S') {
                    counter++;
                } else if (grid[i - 1][j - 1] == 'M' && grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S'){
                    counter++;
                } else if (grid[i - 1][j - 1] == 'S' && grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M'){
                    counter++;
                } else if (grid[i - 1][j - 1] == 'S' && grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'M'){
                    counter++;
                }
            }
        }
    }

    cout << counter << endl;

    return 0;
}


/*
 * part 1
 for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'X') {
                if (j + 3 < cols && grid[i][j + 1] == 'M' && grid[i][j + 2] == 'A' && grid[i][j + 3] == 'S') {
                    counter++;
                }
                if (i - 3 >= 0 && j + 3 < cols && grid[i - 1][j + 1] == 'M' && grid[i - 2][j + 2] == 'A' && grid[i - 3][j + 3] == 'S') {
                    counter++;
                }
                if (i - 3 >= 0 && grid[i - 1][j] == 'M' && grid[i - 2][j] == 'A' && grid[i - 3][j] == 'S') {
                    counter++;
                }
                if (i - 3 >= 0 && j - 3 >= 0 && grid[i - 1][j - 1] == 'M' && grid[i - 2][j - 2] == 'A' && grid[i - 3][j - 3] == 'S') {
                    counter++;
                }
                if (j - 3 >= 0 && grid[i][j - 1] == 'M' && grid[i][j - 2] == 'A' && grid[i][j - 3] == 'S') {
                    counter++;
                }
                if (i + 3 < rows && j - 3 >= 0 && grid[i + 1][j - 1] == 'M' && grid[i + 2][j - 2] == 'A' && grid[i + 3][j - 3] == 'S') {
                    counter++;
                }
                if (i + 3 < rows && grid[i + 1][j] == 'M' && grid[i + 2][j] == 'A' && grid[i + 3][j] == 'S') {
                    counter++;
                }
                if (i + 3 < rows && j + 3 < cols && grid[i + 1][j + 1] == 'M' && grid[i + 2][j + 2] == 'A' && grid[i + 3][j + 3] == 'S') {
                    counter++;
                }
            }
        }
    }
 */