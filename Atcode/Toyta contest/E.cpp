#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> result(N + 1, 0);  // result[k] is the number of arithmetic subsequences of length k
    vector<vector<unordered_map<int, int>>> dp(N, vector<unordered_map<int, int>>(N));

    for (int i = 0; i < N; ++i) {
        result[1] += 1;  // Every single element is an arithmetic subsequence of length 1
        for (int j = 0; j < i; ++j) {
            ll diff = (ll)A[i] - (ll)A[j];
            if (diff > INT_MAX || diff < INT_MIN) continue; // Skip if difference is not manageable

            int &count = dp[j][i][diff];  // Count of subsequences with difference diff ending at i
            int prev_count = (dp[j].find(diff) == dp[j].end()) ? 0 : dp[j][diff];

            count = (count + prev_count + 1) % MOD;  // Extend previous or start new subsequence
            result[2] = (result[2] + 1) % MOD;  // Update the count of length 2 subsequences
            if (prev_count > 0) {
                result[3] = (result[3] + prev_count) % MOD;  // Update length 3 subsequences
            }
        }
    }

    // Print the results for each length from 1 to N
    for (int k = 1; k <= N; ++k) {
        if (k > 1) cout << " ";
        cout << result[k];
    }
    cout << "\n";

    return 0;
}
