#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<ll> vertexWeight(N);
    for (int i = 0; i < N; ++i) {
        cin >> vertexWeight[i];
    }

    vector<vector<pli>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Dijkstra's algorithm
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<ll> dist(N, numeric_limits<ll>::max());
    dist[0] = vertexWeight[0];
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            ll cost = d + vertexWeight[v] + weight;
            if (cost < dist[v]) {
                dist[v] = cost;
                pq.push({cost, v});
            }
        }
    }


    for (int i = 1; i < N; ++i) {
        if (i > 1) cout << " ";
        cout << dist[i];
    }
    cout << "\n";

    return 0;
}
