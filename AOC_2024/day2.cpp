#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define db double
#define str string
#define vi vector<int>
#define pb push_back


bool isValidSequence(const vi& C, bool down) {
    for (int i = 1; i < C.size(); i++) {
        int diff = down ? (C[i - 1] - C[i]) : (C[i] - C[i - 1]);
        if (diff > 3 || diff < 1) {
            return false;
        }
    }
    return true;
}

bool canBecomeValidByRemovingOne(const vi& C, bool down) {
    for (int i = 0; i < C.size(); i++) {
        vi temp = C;
        temp.erase(temp.begin() + i);
        if (isValidSequence(temp, down)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi C;
    int count = 0, number;
    str s;

    for (int i = 0; i < 1000; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> number) {
            C.pb(number);
        }

        if (C.size() < 2) {
            count++;
            C.clear();
            continue;
        }

        int hore = 0, dole = 0;
        for (int k = 1; k < C.size(); k++) {
            if (C[k] < C[k - 1]) {
                dole++;
            } else {
                hore++;
            }
        }

        bool down = dole > hore;

        if (isValidSequence(C, down) || canBecomeValidByRemovingOne(C, down)) {
            count++;
        }

        C.clear();
    }

    cout << count << endl;

    // 488



    /*
     * part 1
     vi C;
    int count = 0, number, miss = 0;
    bool down = false;
    str s;
    for (int i = 0; i < 1000; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> number) {
            C.pb(number);
        }
        if (C[0] > C[1]) {
            down = true;
        }
        for (int j = 1; j < C.size(); j++) {
            if (down) {
                if ((C[j - 1] - C[j]) > 3 || (C[j - 1] - C[j]) < 1) {
                    miss++;
                }
            } else {
                if ((C[j] - C[j - 1]) > 3 || (C[j] - C[j - 1]) < 1) {
                    miss++;
                }
            }
        }
        if (miss == 0) {
            count++;
        }
        C.clear();
        miss = 0;
        down = false;
    }
    cout << count << endl;
     */

    return 0;
}