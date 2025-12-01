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

    vi ONE, TWO, NUM;
    string line;
    int num1, num2, number, checking;
    ll counter = 0;
    bool miss = false;

    for (int i = 0; i < 1176; i++) { //1176
        getline(cin, line);
        stringstream ss(line);
        char delimiter;
        ss >> num1 >> delimiter >> num2;
        ONE.push_back(num1);
        TWO.push_back(num2);
    }

    for (int i = 0; i < 189; i++) { //189
        getline(cin, line);
        stringstream ss(line);
        while (ss >> number) {
            NUM.push_back(number);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }
        for(int x = 0; x < 5; x++) {
            for (int j = 0; j < NUM.size(); j++) {
                checking = NUM[NUM.size() - 1 - j];
                for (int k = 0; k < ONE.size(); k++) {
                    if (checking == ONE[k]) {
                        for (int l = 0; l < NUM.size() - j - 1; l++) {
                            if (NUM[l] == TWO[k]) {
                                int mistake = NUM[l];
                                NUM.erase(NUM.begin() + l);
                                NUM.insert(NUM.begin() + (NUM.size() - j), mistake);
                                l = -1;
                                miss = true;
                            }
                        }
                    }
                }
            }
        }


        if(miss) {
            counter += floor((NUM[NUM.size() / 2]));
        }
        miss = false;
        NUM.clear();
    }

    cout << counter << endl;

    return 0;
}

// 4130

/*
 * part1
 vi ONE, TWO, NUM;
    string line;
    int num1, num2, number, checking;
    ll counter = 0;
    bool miss;

    for (int i = 0; i < 1176; i++) {
        getline(cin, line);
        stringstream ss(line);
        char delimiter;
        ss >> num1 >> delimiter >> num2;
        ONE.push_back(num1);
        TWO.push_back(num2);
    }

    for (int i = 0; i < 189; i++) {
        getline(cin, line);
        stringstream ss(line);
        while (ss >> number) {
            NUM.push_back(number);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }
        for(int j = 0; j < NUM.size(); j++){
            checking = NUM[NUM.size() - 1 - j];
            for(int k = 0; k < ONE.size(); k++){
                if(checking == ONE[k]){
                    for (int l = 0; l < NUM.size() - j; l++) {
                        if(NUM[l] == TWO[k]){
                            miss = true;
                            break;
                        }
                    }
                }
            }
        }
        if (!miss){
            counter += floor((NUM[NUM.size() / 2]));
        }
        miss = false;
        NUM.clear();
    }

    cout << counter << endl;
 */