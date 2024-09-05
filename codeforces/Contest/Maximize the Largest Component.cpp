#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int n, m;

int dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == '.')
        return 0;

    visited[i][j] = true;
    int componentSize = 1;

    componentSize += dfs(i + 1, j);
    componentSize += dfs(i - 1, j);
    componentSize += dfs(i, j + 1);
    componentSize += dfs(i, j - 1);

    return componentSize;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        grid.assign(n, vector<char>(m));
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        int maxComponentSize = 0;

        // Try setting all cells in a row and column to '#'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Reset visited array
                for (int k = 0; k < n; ++k)
                    fill(visited[k].begin(), visited[k].end(), false);

                visited[i][j] = true;

                int componentSize = dfs(i, j);

                maxComponentSize = max(maxComponentSize, componentSize);
            }
        }

        cout << maxComponentSize << endl;
    }

    return 0;
}
