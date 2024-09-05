#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<vector<int>> freq_a(n + 1, vector<int>(26, 0));
        vector<vector<int>> freq_b(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                freq_a[i + 1][j] = freq_a[i][j];
                freq_b[i + 1][j] = freq_b[i][j];
            }
            freq_a[i + 1][a[i] - 'a']++;
            freq_b[i + 1][b[i] - 'a']++;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; // make zero-based

            vector<int> count_a(26, 0), count_b(26, 0);

            for (int j = 0; j < 26; ++j) {
                count_a[j] = freq_a[r][j] - freq_a[l][j];
                count_b[j] = freq_b[r][j] - freq_b[l][j];
            }

            int changes_needed = 0;
            for (int j = 0; j < 26; ++j) {
                changes_needed += abs(count_a[j] - count_b[j]);
            }

            cout << changes_needed / 2 << endl; // since each change impacts two characters
        }
    }

    return 0;
}
