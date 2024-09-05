#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int q;
        cin >> q;

        vector<int> positions(q), values(q);
        for (int i = 0; i < q; ++i) {
            cin >> positions[i] >> values[i];
            --positions[i]; // convert to 0-based index
        }

        // Find initial boundaries of the subarray that needs to be sorted
        int left = n - 1, right = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                left = i - 1;
                break;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] > a[i + 1]) {
                right = i + 1;
                break;
            }
        }

        // Output initial boundaries
        if (left > right) {
            cout << "-1 -1\n";
        } else {
            cout << (left + 1) << " " << (right + 1) << "\n";
        }

        // Process each modification
        for (int i = 0; i < q; ++i) {
            int pos = positions[i];
            int val = values[i];

            a[pos] = val;

            // Update left boundary
            if (pos > 0 && a[pos] < a[pos - 1]) {
                left = min(left, pos - 1);
            } else if (pos == 0) {
                left = 0;
            }

            // Update right boundary
            if (pos < n - 1 && a[pos] > a[pos + 1]) {
                right = max(right, pos + 1);
            } else if (pos == n - 1) {
                right = n - 1;
            }

            // Output current boundaries
            if (left > right) {
                cout << "-1 -1\n";
            } else {
                cout << (left + 1) << " " << (right + 1) << "\n";
            }
        }
    }

    return 0;
}

