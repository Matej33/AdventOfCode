#include <bits/stdc++.h>
#include <regex>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define db double
#define vi vector<int>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string input;
    getline(cin, input);

    ll count = 0;
    bool x = true;

    // Combined regex pattern to match mul(), do(), and don't()
    regex pattern(R"((mul\((\d{1,3}),(\d{1,3})\))|(do\(\))|(don't\(\)))");
    smatch matches;

    auto it = input.cbegin();
    while (regex_search(it, input.cend(), matches, pattern)) {
        // Check if the match is for mul()
        if (matches[1].matched && x) {
            count += stoi(matches[2]) * stoi(matches[3]);
        }
            // Check if the match is for do()
        else if (matches[4].matched) {
            x = true;
        }
            // Check if the match is for don't()
        else if (matches[5].matched) {
            x = false;
        }

        // Move the iterator forward
        it = matches.suffix().first;
    }
    cout << count << endl;

    // 14811759 -
    // 7273782 - 6776313
    // 17869209 - 16084974
    // 5345545 -
    // 9037140 -
    // 18422941 -

    // 72760376 too high

    // 70478672 - yesss

    // 19009496 too low


    /*
     * part 1
    string input;
    getline(cin, input);
    ll count = 0;
    regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    smatch matches;
    auto it = input.cbegin();
    while (regex_search(it, input.cend(), matches, pattern)) {
        it = matches.suffix().first;
        count += stoi(matches[1]) * stoi(matches[2]);
    }
    cout << count << endl;
// 30607507
// 26871200
// 26414577
// 29098508
// 25376181
// 26362555

// 164730528
     */

    return 0;
}

