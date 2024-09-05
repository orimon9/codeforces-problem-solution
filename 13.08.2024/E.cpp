#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<long long> heights(w);
        for (int i = 0; i < w; ++i) {
            cin >> heights[i];
        }

        // Sort the gorillas' heights in descending order to maximize the spectacle.
        sort(heights.rbegin(), heights.rend());

        long long max_spectacle = 0;
        int max_gorillas_in_k_square = k * k;

        // Calculate the maximum spectacle based on the top k*k gorillas
        for (int i = 0; i < min(w, max_gorillas_in_k_square); ++i) {
            max_spectacle += heights[i];
        }

        cout << max_spectacle << '\n';
    }

    return 0;
}
