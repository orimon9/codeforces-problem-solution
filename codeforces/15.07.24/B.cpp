#include <iostream>
#include <string>
using namespace std;

string canMakeMajorityOne(int n, const string &s) {
    if (n == 1) {
        return s == "1" ? "YES" : "NO";
    }

    int ones = 0;
    for (char c : s) {
        if (c == '1') {
            ones++;
        }
    }

    if (ones > n / 2) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << canMakeMajorityOne(n, s) << endl;
    }
    return 0;
}
