#include <iostream>
#include <cmath>
using namespace std;

bool check(long long x, long long m) {
    long long r_b = m * m;
    long long c_sum = (m * (m + 1) * (2 * m + 1)) / 6; // Sum of squares formula
    return c_sum >= r_b;
}

long long getMaxSquare(long long x) {
    long long l = 0, r = sqrt(x) + 1, max_s = 0;
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (check(x, m)) {
            max_s = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return max_s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        long long maxSquare = getMaxSquare(x);
        cout << maxSquare << endl;
    }
    return 0;
}
