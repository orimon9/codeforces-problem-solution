#include <bits/stdc++.h>
using namespace std;


bool MoveRook(int n, int m, vector<pair<int, int>>& rooks) {
    set<int> occ_r;
    set<int> occ_c;
    for (const auto& rook : rooks) {
        occ_r.insert(rook.first);
        occ_c.insert(rook.second);
    }

    for (const auto& rook : rooks) {
        int x = rook.first;
        int y = rook.second;

        for (int f = 1; f <= n; ++f) {
            if (f!= y && occ_c.find(f) == occ_c.end()) {
                return true;
            }
        }

        for (int g = 1; g <= n; ++g) {
            if (g != x && occ_r.find(g) == occ_r.end()) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int a, b;
        cin >> a >> b;

        vector<pair<int, int>> rooks(b);
        for (int i = 0; i < b; ++i) {
            cin >> rooks[i].first >> rooks[i].second;
        }

        if (MoveRook(a, b, rooks)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
