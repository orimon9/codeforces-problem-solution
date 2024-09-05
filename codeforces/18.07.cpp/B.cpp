#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canTransform(const string &s, const string &t) {
    int countS = 0, countT = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') countS++;
        if (t[i] == '1') countT++;

        // At any prefix, the number of '1's in both sequences should be the same
        // for a transformation to be possible
        if (countS != countT) {
            return false;
        }
    }
    return true;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        // Call function to check if transformation is possible
        if (canTransform(s, t)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
