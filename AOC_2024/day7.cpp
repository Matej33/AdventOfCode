#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define db double
#define str string
#define vi vector<int>
#define pb push_back

bool canFormTarget(ll target, vi &nums, int index, ll current) {
    if (index == nums.size()) {
        return current == target;
    }
    if (canFormTarget(target, nums, index + 1, current + nums[index])) {
        return true;
    }
    if (canFormTarget(target, nums, index + 1, current * nums[index])) {
        return true;
    }
    if (canFormTarget(target, nums, index + 1, stoll(to_string(current) + to_string(nums[index])))) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str input;
    ull counter = 0;
    while (getline(cin, input) && input != "konec") {
        stringstream ss(input);
        string left;
        getline(ss, left, ':');
        ll target = stoll(left);
        vi nums;
        int num;
        while (ss >> num) {
            nums.pb(num);
        }
        if (canFormTarget(target, nums, 1, nums[0])) {
            counter += target;
        }

    }
    cout << counter << endl;
    return 0;
}


/*
 * part 1
 bool canFormTarget(ll target, vi& nums, int index, ll current){
    if (index == nums.size()) {
        return current == target;
    }
    if (canFormTarget(target, nums, index + 1, current + nums[index])) {
        return true;
    }
    if (canFormTarget(target, nums, index + 1, current * nums[index])) {
        return true;
    }
    return false;
}

 int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    str input;
    ull counter = 0;
    while (getline(cin, input) && input != "konec") {
        stringstream ss(input);
        string left;
        getline(ss, left, ':');
        ll target = stoll(left);
        vi nums;
        int num;
        while (ss >> num) {
            nums.pb(num);
        }
        if (canFormTarget(target, nums, 1, nums[0])) {
            counter += target;
        }

    }
    cout << counter << endl;
    return 0;
}

 */