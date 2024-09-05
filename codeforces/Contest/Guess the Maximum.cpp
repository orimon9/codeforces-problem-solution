#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;

// Function to check if a point exists in the map
bool exists(const unordered_map<int, unordered_map<int, int>>& pointMap, int x, int y) {
    return pointMap.count(x) && pointMap.at(x).count(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<pii> points(n);
        unordered_map<int, unordered_map<int, int>> pointMap;

        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
            pointMap[x][y] = i + 1;
        }

        bool found = false;

        for (int i = 0; i < n && !found; ++i) {
            int x1 = points[i].first;
            int y1 = points[i].second;

            if (exists(pointMap, x1 + d, y1) && exists(pointMap, x1, y1 + d)) {
                int j = pointMap[x1 + d][y1];
                int k = pointMap[x1][y1 + d];
                cout << (i + 1) << " " << j << " " << k << "\n";
                found = true;
                break;
            }

            if (exists(pointMap, x1 - d, y1) && exists(pointMap, x1, y1 - d)) {
                int j = pointMap[x1 - d][y1];
                int k = pointMap[x1][y1 - d];
                cout << (i + 1) << " " << j << " " << k << "\n";
                found = true;
                break;
            }

            if (exists(pointMap, x1 + d, y1) && exists(pointMap, x1, y1 - d)) {
                int j = pointMap[x1 + d][y1];
                int k = pointMap[x1][y1 - d];
                cout << (i + 1) << " " << j << " " << k << "\n";
                found = true;
                break;
            }

            if (exists(pointMap, x1 - d, y1) && exists(pointMap, x1, y1 + d)) {
                int j = pointMap[x1 - d][y1];
                int k = pointMap[x1][y1 + d];
                cout << (i + 1) << " " << j << " " << k << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "0 0 0\n";
        }
    }

    return 0;
}
