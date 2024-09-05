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
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> rectangles(n);

        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            rectangles[i] = {a, b};
        }

        vector<int> operations;

        // For each rectangle, consider the operations required to color all columns and all rows
        for (int i = 0; i < n; ++i) {
            int width = rectangles[i].first;
            int height = rectangles[i].second;

            // Max points we can get from this rectangle is min(width, height)
            int max_points = min(width, height);

            // If the required points `k` are less than or equal to `max_points`, we compute the exact operations needed
            for (int j = 1; j <= max_points; ++j) {
                operations.push_back(min(j * height, j * width));
            }
        }

        // Sort the operations in ascending order
        sort(operations.begin(), operations.end());

        // Sum the first `k` smallest operations
        if (k <= operations.size()) {
            int result = 0;
            for (int i = 0; i < k; ++i) {
                result += operations[i];
            }
            cout << result << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
