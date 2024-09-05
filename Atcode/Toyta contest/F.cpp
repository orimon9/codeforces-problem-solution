#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_algorithm(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int Q;
    cin >> Q;

    while (Q--) {
        string T;
        cin >> T;
        string concatenated = T + "$" + S;
        vector<int> z = z_algorithm(concatenated);
        int count = 0;
        int t_size = static_cast<int>(T.size());
        for (int i = t_size + 1; i < static_cast<int>(z.size()); i++) {
            if (z[i] >= t_size) {
                count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}
