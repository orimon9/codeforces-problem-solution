#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> roads(n + 1);
    vector<pair<int, int>> edge_list;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        if (c == 1) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            edge_list.push_back({u, v});
        }
    }

    // Check all degrees are even and the graph is connected
    bool isEulerian = true;
    vector<bool> visited(n + 1, false);

    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty()) {
            if (start == -1) start = i;
            if (adj[i].size() % 2 != 0) {
                isEulerian = false;
                break;
            }
        }
    }

    function<test(int)> dfs = [&](int node) {
        visited[node] = true;
        for (int neighbour : adj[node])
            if (!visited[neighbour])
                dfs(neighbour);
    };

    if (start != -1) {
        dfs(start);
        for (int i = 1; i <= n; i++) {
            if (!adj[i].empty() && !visited[i]) {
                isEulerian = false;
                break;
            }
        }
    }

    if (!isEulerian) {
        cout << "NO\n";
        return;
    }

    // Hierholzer's algorithm to find an Eulerian circuit
    stack<int> stack, circuit;
    stack.push(start);

    while (!stack.empty()) {
        int v = stack.top();
        if (!adj[v].empty()) {
            int u = adj[v].back();
            stack.push(u);
            adj[v].pop_back(); // Remove edge v-u
            adj[u].erase(find(adj[u].begin(), adj[u].end(), v)); // Remove edge u-v
        } else {
            stack.pop();
            circuit.push(v);
        }
    }

    cout << "YES\n";
    cout << circuit.size() - 1 << "\n";
    while (!circuit.empty()) {
        cout << circuit.top() << " ";
        circuit.pop();
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
