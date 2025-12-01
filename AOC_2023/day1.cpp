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

    string x;
    int counter = 0;
    while (true){
        int first, last;
        bool help = true;
        cin >> x;
        if (x.contains('^')) {
            cout << counter << endl;
            return 0;
        }
        for (int i = 0; i < x.length(); i++) {
            if(help){
                if(x[i] == '1'){
                    first = 1;
                    last = 1;
                    help = false;
                } else if(x[i] == '2'){
                    first = 2;
                    last = 2;
                    help = false;
                } else if(x[i] == '3'){
                    first = 3;
                    last = 3;
                    help = false;
                } else if(x[i] == '4'){
                    first = 4;
                    last = 4;
                    help = false;
                } else if(x[i] == '5'){
                    first = 5;
                    last = 5;
                    help = false;
                } else if(x[i] == '6'){
                    first = 6;
                    last = 6;
                    help = false;
                } else if(x[i] == '7'){
                    first = 7;
                    last = 7;
                    help = false;
                } else if(x[i] == '8'){
                    first = 8;
                    last = 8;
                    help = false;
                } else if(x[i] == '9'){
                    first = 9;
                    last = 9;
                    help = false;
                }
            }else{
                if(x[i] == '1'){
                    last = 1;
                } else if(x[i] == '2'){
                    last = 2;
                } else if(x[i] == '3'){
                    last = 3;
                } else if(x[i] == '4'){
                    last = 4;
                } else if(x[i] == '5'){
                    last = 5;
                } else if(x[i] == '6'){
                    last = 6;
                } else if(x[i] == '7'){
                    last = 7;
                } else if(x[i] == '8'){
                    last = 8;
                } else if(x[i] == '9'){
                    last = 9;
                }
            }
        }
        int sum = first*10 + last;
        counter += sum;
    }


    return 0;
}