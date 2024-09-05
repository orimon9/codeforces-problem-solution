
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n), c(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> c[j];
    }


    int min_net_cost = 1e6 + 1;
    for (int i = 0; i < n; ++i) {
        min_net_cost = min(min_net_cost, a[i] - b[i]);
    }

    long long total_experience = 0;
    for (int j = 0; j < m; ++j) {
        if (min_net_cost > 0) {

            long long cycles = c[j] / min_net_cost;
            total_experience += 2 * cycles;
        }
    }

    cout << total_experience << endl;
    return 0;
}
