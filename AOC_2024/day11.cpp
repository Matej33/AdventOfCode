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

class Num {
public:
    ull num, times;
    Num(ull x, ull y) : num(x), times(y) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Num> V;
    {
        V.eb(0, 1);
        V.eb(4, 1);
        V.eb(4979, 1);
        V.eb(24, 1);
        V.eb(4356119, 1);
        V.eb(914, 1);
        V.eb(85734, 1);
        V.eb(698829, 1);
    }

    for (int i = 0; i < 75; i++) {
        vector<Num> newV;
        for (int j = 0; j < V.size(); j++) {
            if (V[j].num == 0) {
                newV.eb(1, V[j].times);
            } else if (to_string(V[j].num).length() % 2 == 0) {
                str x = to_string(V[j].num);
                ull time = V[j].times;
                newV.eb(stoll(x.substr(0, x.length() / 2)), time);
                newV.eb(stoll(x.substr(x.length() / 2, x.length())), time);
            } else {
                newV.eb(V[j].num * 2024, V[j].times);
            }
        }

        unordered_map<ull, ull> num_count;
        for (int j = 0; j < newV.size(); j++) {
            num_count[newV[j].num] += newV[j].times;
        }

        V.clear();
        for (auto& entry : num_count) {
            V.eb(entry.first, entry.second);
        }
    }

    ull counter = 0;
    for (int i = 0; i < V.size(); i++) {
        counter += V[i].times;
    }

    cout << counter << endl;

    return 0;
}
// 223894720281135

/*
 * part1
 *
 vector<ll> V = {0, 4, 4979, 24, 4356119, 914, 85734, 698829};
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < V.size(); j++) {
            if(V[j] == 0){
                V[j] = 1;
            } else if(to_string(V[j]).length() % 2 == 0){
                str x = to_string(V[j]);
                V[j] = stoll(x.substr(0, x.length()/2));
                V.insert(V.begin() + j, stoll(x.substr(x.length()/2, x.length())));
                j++;
            } else {
                V[j] = V[j]*2024;
            }
        }
    }
    cout << V.size() << endl;
 */