#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cin >> s;

        long long total_score = 0;

        // Calculate initial score assuming no operations are performed
        for (int i = 0; i < n; ++i) {
            total_score += a[i];
        }

        vector<long long> gains;

        // Calculate the potential gains if we swap each L with an R on the right
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                // Gain if we swap this L to the closest possible R
                gains.push_back(a[n - i - 1] - a[i]);
            } else if (s[i] == 'R') {
                // Gain if we swap this R to the closest possible L
                gains.push_back(a[i] - a[n - i - 1]);
            }
        }

        // Sort the potential gains in decreasing order
        sort(gains.rbegin(), gains.rend());

        // Apply the best gains to maximize the score
        for (int i = 0; i < n; ++i) {
            if (gains[i] > 0) {
                total_score += gains[i];
            }
        }

        cout << total_score << '\n';
    }

    return 0;
}
