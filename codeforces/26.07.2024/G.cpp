#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        UnionFind uf(n + 1);
        vector<pair<int, int>> friendships(m);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            friendships[i] = {a, b};
        }

        // Unite all friends pairs
        for (const auto& [a, b] : friendships) {
            uf.unite(a, b);
        }

        // Count distinct components
        int components = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            int root = uf.find(i);
            if (!visited[root]) {
                visited[root] = true;
                components++;
            }
        }

        // Each component needs its own set of edges, thus we need `components` edges
        cout << components << endl;
    }

    return 0;
}
