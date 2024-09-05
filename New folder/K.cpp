#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canCover(vector<long long>& events, long long start, long long interval) {
    long long current = start;
    for (long long event : events) {
        if (event < current) {
            return false;
        }
        current = max(current, event) + interval;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> events(n);
    for (int i = 0; i < n; ++i) {
        cin >> events[i];
    }

    vector<long long> options(m);
    for (int i = 0; i < m; ++i) {
        cin >> options[i];
    }

    // Iterate over all possible starting minutes
    for (long long start : events) {
        // Iterate over all interval options
        for (int j = 0; j < m; ++j) {
            // Check if the interval option covers all events
            if (canCover(events, start, options[j])) {
                // Output the result
                cout << "YES" << endl;
                cout << start << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    // If no suitable option is found
    cout << "NO" << endl;

    return 0;
}
