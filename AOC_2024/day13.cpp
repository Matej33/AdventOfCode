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

    ll final = 0;

    for(int i = 0; i < 2; i++) {

        ll ax = 0, ay = 0, bx = 0, by = 0, px = 0, py = 0, t = 0, t2 = 0;
        float a, b, a2, b2;

        string first, second, third;
        getline(cin, first);
        getline(cin, second);
        getline(cin, third);
        cin.ignore();

        sscanf(first.c_str(), "Button A: X+%d, Y+%d", &ax, &ay);
        sscanf(second.c_str(), "Button B: X+%d, Y+%d", &bx, &by);
        sscanf(third.c_str(), "Prize: X=%d, Y=%d", &px, &py);
        //px += 10000000000000;
        //py += 10000000000000;

        b = static_cast<float>(py * ax - px * ay) / (ax * by - ay * bx);
        a = static_cast<float>(px - b * bx) / ax;

        a2 = static_cast<float>(py * bx - px * by) / (ay * bx - ax * by);
        b2 = static_cast<float>(px - a * ax) / bx;

        float fractionalPartA = fmod(a, 1.0);
        float fractionalPartB = fmod(b, 1.0);
        float fractionalPartA2 = fmod(a2, 1.0);
        float fractionalPartB2 = fmod(b2, 1.0);

        if(abs(fractionalPartA) == 0 && abs(fractionalPartB) == 0) {
            t = a * 3 + b;
        }
        if(abs(fractionalPartA2) == 0 && abs(fractionalPartB2) == 0) {
            t2 = a2 * 3 + b2;
        }
        if(t < t2 && t != 0) {
            final += t;
        } else if(t2 != 0) {
            final += t2;
        }
    }

    cout << final << endl;

    return 0;
}

// 163458394775552 too high

// 153458401583104 too low


/*
 * part 1
    ll final = 0;

    for(int i = 0; i < 320; i++) {
        int t = 0, counterX = 0, counterY = 0, times = 0;
        ll ax = 0, ay = 0, bx = 0, by = 0, px = 0, py = 0;
        bool idk = true;

        string first, second, third;
        getline(cin, first);
        getline(cin, second);
        getline(cin, third);
        cin.ignore();

        sscanf(first.c_str(), "Button A: X+%d, Y+%d", &ax, &ay);
        sscanf(second.c_str(), "Button B: X+%d, Y+%d", &bx, &by);
        sscanf(third.c_str(), "Prize: X=%d, Y=%d", &px, &py);

        while (counterY < py) {
            counterY += by;
            counterX += bx;
            t++;
            times++;
        }
        while (idk && times > 0) {
            counterY -= by;
            counterX -= bx;
            t--;
            times--;
            while (counterY < py) {
                counterY += ay;
                counterX += ax;
                t += 3;
            }
            if (counterY == py && counterX == px) {
                idk = false;
            }
        }
        if (times > 0) {
            final += t;
        }
    }
    cout << final << endl;
 */