
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string canReach(int n, int m, int k, string &river) {
    vector<bool> visited(n + 2, false);  // Includes the left bank (0) and right bank (n+1)
    queue<pair<int, int>> q;  // <position, swam>
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty()) {
        auto [pos, swam] = q.front();
        q.pop();

        // Check all possible jumps
        for (int jump = 1; jump <= m; ++jump) {
            int newPos = pos + jump;
            if (newPos > n + 1) break;
            if (newPos == n + 1) return "YES";  // Reached the right bank
            if (river[newPos - 1] == 'C') continue;  // Can't land on a crocodile
            if (!visited[newPos]) {
                visited[newPos] = true;
                q.push({newPos, swam});
            }
        }

        // Check swimming to the next segment if currently in water
        if (pos > 0 && pos <= n && river[pos - 1] == 'W' && swam < k) {
            int newPos = pos + 1;
            if (newPos > n + 1) continue;
            if (newPos == n + 1) return "YES";  // Reached the right bank
            if (!visited[newPos]) {
                visited[newPos] = true;
                q.push({newPos, swam + 1});
            }
        }
    }

    return "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        string river;
        cin >> n >> m >> k >> river;
        cout << canReach(n, m, k, river) << endl;
    }
    return 0;
}
