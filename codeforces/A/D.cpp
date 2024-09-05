#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> heights(n, vector<int>(m));
        vector<vector<char>> types(n, vector<char>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> heights[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> types[i][j];
            }
        }

        // Calculate sums of snowy caps (type '0') and non-caps (type '1')
        vector<vector<long long>> sum_snowy(n + 1, vector<long long>(m + 1, 0));
        vector<vector<long long>> sum_non_snowy(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sum_snowy[i + 1][j + 1] = sum_snowy[i][j + 1] + sum_snowy[i + 1][j] - sum_snowy[i][j];
                sum_non_snowy[i + 1][j + 1] = sum_non_snowy[i][j + 1] + sum_non_snowy[i + 1][j] - sum_non_snowy[i][j];

                if (types[i][j] == '0') {
                    sum_snowy[i + 1][j + 1] += heights[i][j];
                } else {
                    sum_non_snowy[i + 1][j + 1] += heights[i][j];
                }
            }
        }

        // Check each k x k submatrix
        bool possible = false;

        for (int i = 0; i + k <= n; ++i) {
            for (int j = 0; j + k <= m; ++j) {
                // Calculate the sums of snowy caps and non-caps in this k x k submatrix
                long long snowy_sum = sum_snowy[i + k][j + k] - sum_snowy[i][j + k] - sum_snowy[i + k][j] + sum_snowy[i][j];
                long long non_snowy_sum = sum_non_snowy[i + k][j + k] - sum_non_snowy[i][j + k] - sum_non_snowy[i + k][j] + sum_non_snowy[i][j];

                if (snowy_sum == non_snowy_sum) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
