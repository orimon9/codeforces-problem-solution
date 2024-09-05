#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
typedef long long ll;

const ll inf = numeric_limits<ll>::max();

void dfs(int u, int parent, vector<vector<int>> &graph, vector<ll> &a, vector<ll> &dp0, vector<ll> &dp1) {
    dp0[u] = 0;  // If we kill this monster
    dp1[u] = a[u];  // If we don't kill this monster

    for (int v : graph[u]) {
        if (v == parent) continue;
        dfs(v, u, graph, a, dp0, dp1);

        dp0[u] += dp1[v];  // If u is killed, v must not be killed
        dp1[u] += min(dp0[v], dp1[v]);  // If u is not killed, choose the optimal for v
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<ll> dp0(n + 1), dp1(n + 1);
    dfs(1, -1, graph, a, dp0, dp1);

    cout << min(dp0[1], dp1[1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
