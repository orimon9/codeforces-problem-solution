#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();

        vector<int> dp(n, 500); // Use a large number initially
        vector<int> count(n, 0);

        // Base case
        dp[0] = 0;
        count[0] = 1;

        for (int i = 0; i < n; i++) {
            // Continue without removing anything at position i
            if (i > 0) {
                dp[i] = dp[i-1];
                count[i] = count[i-1];
            }

            // Check if substring s[i-m+1 .. i] == t
            if (i >= m - 1) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (s[i - m + 1 + j] != t[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    int prev_cost = (i >= m ? dp[i-m] : 0) + 1;
                    if (prev_cost < dp[i]) {
                        dp[i] = prev_cost;
                        count[i] = (i >= m ? count[i-m] : 1);
                    } else if (prev_cost == dp[i]) {
                        count[i] += (i >= m ? count[i-m] : 1);
                        count[i] %= MOD;
                    }
                }
            }
        }

        int min_moves = dp[n-1];
        int ways = count[n-1];
        cout << min_moves << " " << ways << "\n";
    }
    return 0;
}
