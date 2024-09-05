#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct ValueIndex {
    int value;
    int index;
};

void solve() {
    int n;
    cin >> n;
    vector<ValueIndex> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].value;
        a[i].index = i + 1;  // Store original index
    }

    // Sort by value to easily find pairs with differences divisible by i
    sort(a.begin(), a.end(), [](const ValueIndex &x, const ValueIndex &y) {
        return x.value < y.value;
    });

    // To store the results
    vector<pair<int, int>> results;

    // Try to form edges
    for (int i = 1; i < n; ++i) {
        bool found = false;
        // Start from the second element and try to find a pair for operation i
        for (int j = 0; j < i; ++j) {
            if (abs(a[i].value - a[j].value) % i == 0) {
                results.push_back({a[j].index, a[i].index});
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for (auto &res : results) {
        cout << res.first << " " << res.second << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
