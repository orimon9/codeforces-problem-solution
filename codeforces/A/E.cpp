#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countKGoodSubarrays(int n, int k) {
    long long result = 0;
    int left = 0;
    int onesCount = 0;

    for (int right = 0; right < n; ++right) {
        // Count '1's in the binary representation of a[right]
        onesCount += __builtin_popcount(right);

        // Shrink the window until onesCount <= k
        while (onesCount > k) {
            onesCount -= __builtin_popcount(left);
            ++left;
        }

        // All subarrays ending at `right` and starting from any position between `left` and `right` are k-good
        result = (result + (right - left + 1)) % MOD;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        int k;
        cin >> n >> k;

        // Calculate the number of k-good subarrays
        int result = countKGoodSubarrays(n, k);
        cout << result << endl;
    }

    return 0;
}
