#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

bool kproper(const string &s, int k) {
    char f_char = s[0];
    for (int z = 0; z < k; ++z) {
        if (s[z] != f_char) {
            return false;
        }
    }
    for (int z = k; z < s.size(); ++z) {
        if (s[z] == s[z - k]) {
            return false;
        }
    }
    return true;
}

string oper(const string &s, int p) {
    string t = s.substr(0, p);
    reverse(t.begin(), t.end());
    string out = t + s.substr(p);
    rotate(out.begin(), out.begin() + p, out.end());
    return out;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, k;
        string s;
        cin >> m >> k;
        cin >> s;

        bool get = false;
        for (int y = 1; y <= m; ++y) {
            string out_chng = oper(s, y);
            if (kproper(out_chng, k)) {
                cout << y << endl;
                get = true;
                break;
            }
        }
        if (!get) {
            cout << -1 << endl;
        }
    }

    return 0;
}
