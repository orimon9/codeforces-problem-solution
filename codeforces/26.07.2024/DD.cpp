#include <iostream>
#include <vector>
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
        vector<int> a_values, b_values, c_values;

        for (int a = 1; a <= x; ++a) {
            a_values.push_back(a);
        }
        for (int b = 1; b <= x; ++b) {
            b_values.push_back(b);
        }
        for (int c = 1; c <= x; ++c) {
            c_values.push_back(c);
        }

        for (int a : a_values) {
            for (int b : b_values) {
                for (int c : c_values) {
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
