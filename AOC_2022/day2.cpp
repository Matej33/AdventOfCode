#include <iostream>

using namespace std;

int main(){
    string x;
    long pocitadlo = 0;
    for(int i = 0; i < 2500; i++) {
        getline(cin, x);
        if(x[0] == 'A' && x[2] == 'X') pocitadlo += 3;       // v parte 1 += 4
        else if (x[0] == 'A' && x[2] == 'Y') pocitadlo += 4; // v parte 1 += 8
        else if (x[0] == 'A' && x[2] == 'Z') pocitadlo += 8; // v parte 1 += 3
        else if (x[0] == 'B' && x[2] == 'X') pocitadlo += 1; // v parte 1 += 1
        else if (x[0] == 'B' && x[2] == 'Y') pocitadlo += 5; // v parte 1 += 5
        else if (x[0] == 'B' && x[2] == 'Z') pocitadlo += 9; // v parte 1 += 9
        else if (x[0] == 'C' && x[2] == 'X') pocitadlo += 2; // v parte 1 += 4
        else if (x[0] == 'C' && x[2] == 'Y') pocitadlo += 6; // v parte 1 += 2
        else if (x[0] == 'C' && x[2] == 'Z') pocitadlo += 7; // v parte 1 += 6
    }
    cout << pocitadlo << endl;
    return 0;
}

//15284 part 1 malo to je
