#include <iostream>

using namespace std;

int main(){
    string line1, line2, line3;
    int x = 0, y = 0, z = 0, pocitadlo = 0;
    bool is;
// TODO
for (int u = 0; u < 5; u++) {
    is = true;
        getline(cin, line1);
        getline(cin, line2);
        getline(cin, line3);
        do {
        if (line1[z] != line2[x] || line1[z] != line3[y] || line2[x] != line3[y]) {
            if (z == line1.length()) {
                z = 0;
                x++;
            } else if (x == line2.length()) {
                x = 0;
                y++;
            } else {
                z++;
            }
            if (y == line3.length()) { is = false;}
        } else {
            if (line2[x] > 64 && line2[x] < 91) {
                pocitadlo += (line2[x] - 38);
                is = false;
            } else {
                pocitadlo += (line2[x] - 96);
               is = false;
            }
        }
    }
    while (is);
}

    cout << pocitadlo << endl;

    return 0;
}


/*
#include <iostream>

using namespace std;

int main(){
string line;
int x = 0, pocitadlo = 0;

for (int i = 0; i < 300; i++){
    getline(cin, line);
    int druha_polovica = (line.length() / 2);
    int copy = druha_polovica;

    for(int j = 0; j <= druha_polovica; j++) {
    if(x == copy) {break;}
        if(line[x] == line[j+copy]) {
            if(line[x] >= 65 && line[x] <= 90) {
                pocitadlo += (line[x] - 38);
                break;
            }
            else {
                pocitadlo += (line[x] - 96);
                break;
            }
        }
        if(j == copy){ x++; j = -1;}
    }
    x = 0;
}
cout << pocitadlo << endl;
    return 0;
}
*/