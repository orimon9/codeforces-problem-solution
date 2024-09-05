#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int lcs_length(const string &a, const string &b) {
    int m = a.length();
    int n = b.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int lcs_len = lcs_length(a, b);
        int min_length = a.length() + b.length() - lcs_len;

        cout << min_length << endl;
    }

    return 0;
}
