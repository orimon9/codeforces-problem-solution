#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        // Prefix sum to track the balance of 1s and 0s
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + (s[i] == '1' ? 1 : -1);
        }

        // Map to count occurrences of each prefix sum value
        unordered_map<int, int> count;
        count[0] = 1;  // base case: empty prefix sum

        long long result = 0;
        for (int i = 1; i <= n; ++i) {
            // Count the number of times the current prefix sum has been seen
            if (count.find(prefix[i]) != count.end()) {
                result = (result + count[prefix[i]]) % MOD;
            }
            // Increment the count of the current prefix sum in the map
            count[prefix[i]]++;
        }

        cout << result << endl;
    }

    return 0;
}
