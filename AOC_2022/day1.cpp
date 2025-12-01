#include <iostream>

using namespace std;

int main(){
    int n = 2249, x = 0, y = 0; // riadky som šlahol do nejakej stránky a spočítalo mi ich, že ich je 2251
    long max1 = 0, max2 = 0, max3 = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        if( x != 0){            // vo worde som si zamenil každý prázdny riadok za číslo 0, viem že mi to ->
            y += x;             // -> nemuselo fungovať lebo mohol by byť aj reálny riadok s číslom nula ->
        }                       // -> a mne by sa tak rozdelil súčet niektorých čísel ale tak dúfal som že nie
        else {
            if(y > max1){
                max3 = max2;
                max2 = max1;
                max1 = y;
            }
            else if(y > max2){
                max3 = max2;
                max2 = y;
            }
            else if(y > max3){
                max3 = y;
            }
            y = 0;
        }
    }
    cout << "top 1 " << max1 << endl;       //top 1 69501
    cout << "top 2 " << max2 << endl;       //top 2 66606
    cout << "top 3 " << max3 << endl;       //top 3 66239
    cout << max1 + max2 + max3 << endl;     //202346

    return 0;
}

