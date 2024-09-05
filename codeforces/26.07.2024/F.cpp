#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Max-heap to store pairs (-a[i], i) to prioritize larger values of a[i]
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({a[i], i});
        }

        long long score = 0;
        while (k-- > 0 && !pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();
            if (value == 0) break; // No more contributions can be made

            score += value;
            a[index] = max(0, a[index] - b[index]);

            if (a[index] > 0) {
                pq.push({a[index], index});
            }
        }

        cout << score << endl;
    }

    return 0;
}
