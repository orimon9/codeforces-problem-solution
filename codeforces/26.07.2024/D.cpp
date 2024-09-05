#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        long long count = 0;

        // Iterate over possible values of a, b, and c
        for (int a = 1; a <= x; ++a) {
            for (int b = 1; b <= x; ++b) {
                for (int c = 1; c <= x; ++c) {
                    if (a + b + c <= x && a * b + a * c + b * c <= n) {
                        count++;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
