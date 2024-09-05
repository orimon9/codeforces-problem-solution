#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m));

        // Read matrix A
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> A[i][j];
            }
        }

        // Special case for 1x1 matrix
        if (n == 1 && m == 1) {
            cout << "-1\n";
            continue;
        }

        // Initialize matrix B as a vector of vectors
        vector<vector<int>> B(n, vector<int>(m));

        // Fill matrix B
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Use modulo operator to rotate values within the range [1, n*m]
                B[i][j] = (A[i][j] % (n * m)) + 1; // Calculate new value
                if (B[i][j] == A[i][j]) {
                    // Further adjust if the new value equals the old one
                    B[i][j] = (B[i][j] % (n * m)) + 1;
                    if (B[i][j] > n * m) {
                        B[i][j] = 1;
                    }
                }
            }
        }

        // Output the matrix B
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << B[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
