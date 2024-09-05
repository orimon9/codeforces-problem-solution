#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {
        cout << "No" << endl;
        return 0;
    }

    for (int j = 0; j < s.length(); ++j) {
        if (isVowel(s[j]) != isVowel(t[j])) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
