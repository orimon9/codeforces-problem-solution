#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long max_x = 0;
    long long max_y = 0;

    for (int i = 1; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }

    // The minimum length of the shorter side of the triangle
    long long min_side_length = max(max_x, max_y);
    cout << min_side_length << endl;

    return 0;
}
