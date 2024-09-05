#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<long long> invFact(n + 1, 1);
    invFact[n] = 1;
    for (int i = n - 1; i >= 2; --i) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    auto binom = [&](int a, int b) {
        if (b > a || b < 0) return 0LL;
        return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
    };

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    dp[0][0] = 1;

    for (int len = 1; len <= n; ++len) {
        for (int groups = 1; groups <= k; ++groups) {
            for (int last = 1; last <= len; ++last) {
                dp[len][groups] = (dp[len][groups] + dp[len - last][groups - 1] * binom(len - 1, last - 1)) % MOD;
            }
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}
