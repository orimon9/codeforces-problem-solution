#include <iostream>
using namespace std;

long long Operation(long long x, long long y, long long k) {
    while (k--) {
        x += 1;
        while (x % y == 0) {
            x /= y;
        }
    }
    return x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        cout << Operation(x, y, k) << endl;
    }
    return 0;
}
