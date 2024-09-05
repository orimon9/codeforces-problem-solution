#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> Q[i];
    }

    vector<vector<pair<int, long long>>> reactions(N);

    for (int i = 0; i < M; ++i) {
        int C0, X;
        cin >> C0 >> X;
        --C0; // Convert to zero-based index

        for (int j = 0; j < X; ++j) {
            long long W;
            int C;
            cin >> W >> C;
            --C; // Convert to zero-based index
            reactions[C0].emplace_back(C, W);
        }
    }

    vector<bool> processed(N, false);
    for (int i = 0; i < N; ++i) {
        if (!processed[i] && !reactions[i].empty()) {
            long long amount = Q[i];
            Q[i] = 0;  // All of it decomposes
            processed[i] = true;
            for (auto& [comp, weight] : reactions[i]) {
                Q[comp] = (Q[comp] + amount * weight) % MOD;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << Q[i] << '\n';
    }

    return 0;
}
