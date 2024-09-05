#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // Use sets to track which rows and columns are constrained
    unordered_set<int> red_rows;
    unordered_set<int> blue_columns;

    // Use map to track specific cell constraints
    unordered_map<int, char> cell_constraints;

    // Process each query
    for (int i = 0; i < q; ++i) {
        int xi, yi;
        char ci;
        cin >> xi >> yi >> ci;
        --xi; // Convert to 0-based index
        --yi; // Convert to 0-based index

        // Apply the constraint
        cell_constraints[xi * m + yi] = ci;

        // Update red_rows and blue_columns sets based on the constraint
        if (ci == 'R') {
            red_rows.insert(xi);
        } else if (ci == 'B') {
            blue_columns.insert(yi);
        }

        // Calculate the minimum cost
        long long num_red_rows = red_rows.size();
        long long num_blue_columns = blue_columns.size();

        long long cost = 0;
        if (num_red_rows > 0 && num_blue_columns > 0) {
            cost = (num_red_rows + num_blue_columns) * (num_red_rows + num_blue_columns);
        }
        cout << cost << "\n";
    }

    return 0;
}
