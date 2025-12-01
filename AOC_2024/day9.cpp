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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream inputFile("C:/School/Programko-Cpp/AOC/AOC_2024/input.txt");
    if (!inputFile) {
        cerr << "nenasiel ho kokot" << endl;
        return 1;
    }

    str input;
    getline(inputFile, input);
    inputFile.close();

    vector<string> V;
    ull counter = 0;
    int bodky = 1, cisla = 1;

    for (ull i = 0; i < input.size(); i++) {
        for (ull j = 0; j < (input[i] - '0'); j++) {
            if (i % 2 == 0) {
                V.pb(to_string(i / 2));
            } else {
                V.pb(".");
            }
        }
    }

    for (ull j = V.size() - 1; j > 0; j--) {
        if (V[j] != ".") {
            cisla = 1;
            for (int k = j - 1; k >= 0; k--) {
                if (V[k] == V[j]) {
                    cisla++;
                } else {
                    break;
                }
            }
            if(V[j] == "0"){
                break;
            }

            for (ull i = 0; i < V.size() && i < j; i++) {
                if (V[i] == ".") {
                    bodky = 1;
                    for (int l = i + 1; l < V.size(); l++) {
                        if (V[l] == ".") {
                            bodky++;
                        } else {
                            break;
                        }
                    }
                    if(i > j){
                        break;
                    }
                    if (cisla <= bodky) {
                        for (int k = 0; k < cisla; k++) {
                            swap(V[i + k], V[j - k]);
                        }
                        break;
                    } else {
                        i += bodky - 1;
                    }
                }
            }
            j -= cisla - 1;
        }
    }

    ull vysledok = 0;
    for (ull i = 0; i < V.size(); i++) {
        if (V[i] != ".") {
            ull value = stoi(V[i]);
            vysledok = i * value;
            counter += vysledok;
        }
    }

    cout << counter << endl;

    // 6469636832766

    return 0;
}

/*
 * part 1
 ifstream inputFile("C:/School/Programko-Cpp/AOC/AOC_2024/input.txt");
    if (!inputFile) {
        cerr << "nenasiel ho kokot" << endl;
        return 1;
    }

    str input;
    getline(inputFile, input);
    inputFile.close();

    vector<string> V;
    ull bodky = 0;
    ull counter = 0;

    for (ull i = 0; i < input.size(); i++) {
        for (ull j = 0; j < (input[i] - '0'); j++) {
            if (i % 2 == 0) {
                V.pb(to_string(i));
            } else {
                V.pb(".");
                bodky++;
            }
        }
    }

    for(ull i = 0; i < V.size(); i++){
        if (V[i] == "." && i < V.size() - bodky) {
            for (ull j = V.size() - 1; j > 0; j--) {
                if (V[j] != "." && i < j) {
                    swap(V[i], V[j]);
                    break;
                }
            }
        }
    }

    for (ull i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }

    ull vysledok = 0;
    for (ull i = 0; i < V.size() - bodky; i++) {
        ull value = stoi(V[i]);
        vysledok = i * value;
        counter += vysledok;
    }

    cout << counter/2 << endl;

    // 6435922584968
 */