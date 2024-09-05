#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MAXN = 200000;

vector<int> adj[MAXN + 1];
int depth[MAXN + 1];
int parent[MAXN + 1];

void dfs(int node, int par) {
    parent[node] = par;
    for (int neighbor : adj[node]) {
        if (neighbor == par) continue;
        depth[neighbor] = depth[node] + 1;
        dfs(neighbor, node);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    while (depth[u] > depth[v]) u = parent[u];
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int distance(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> A(N + 1);
    map<int, vector<int>> valueGroups;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        valueGroups[A[i]].push_back(i);
    }

    // Run DFS from an arbitrary root (node 1)
    depth[1] = 0;
    dfs(1, -1);

    long long result = 0;
    for (const auto& entry : valueGroups) {
        const vector<int>& nodes = entry.second;
        int size = nodes.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                result += distance(nodes[i], nodes[j]);
            }
        }
    }

    cout << result << endl;

    return 0;
}
