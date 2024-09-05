#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x;
        cin >> n >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long count = 0;
        int l = 0;
        long long current_toxicity = 0;

        for (int r = 0; r < n; r++) {
            current_toxicity += a[r];

            // We need to check when g becomes zero due to a reset
            while (current_toxicity > x && l <= r) {
                current_toxicity -= a[l++];
            }

            // Count subarrays ending at r which start anywhere from l to r if current toxicity > 0
            if (current_toxicity > 0) {
                count += (r - l + 1);
            }
        }

        cout << count << endl;
    }

    return 0;
}
