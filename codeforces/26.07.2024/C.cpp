#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i].first >> queries[i].second;
        }

        for (auto& query : queries) {
            int l = query.first - 1;
            int r = query.second - 1;

            string sub_a = a.substr(l, r - l + 1);
            string sub_b = b.substr(l, r - l + 1);

            sort(sub_a.begin(), sub_a.end());
            sort(sub_b.begin(), sub_b.end());

            int changes_needed = 0;
            for (int i = 0; i < sub_a.size(); ++i) {
                if (sub_a[i] != sub_b[i]) {
                    changes_needed++;
                }
            }

            cout << changes_needed << endl;
        }
    }

    return 0;
}

