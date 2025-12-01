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

    vi V, C;
    ull counter = 0;
    for (int i = 0; i < 1000; i++) {
        int x, y;
        cin >> x >> y;
        V.pb(x);
        C.pb(y);
    }
    sort(V.begin(), V.end());
    sort(C.begin(), C.end());
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (V[i] == C[j]) {
                counter+=V[i];
            }
        }
    }
    cout << counter << endl;

    /*
    part 1
     for (int i = 0; i < 1000; i++) {
        counter += abs(V[i] - C[i]);
    }
     */



    return 0;
}