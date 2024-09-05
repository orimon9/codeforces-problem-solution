#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases

    while (t--) {
        long long l, r;
        cin >> l >> r;  // Read l and r for each test case

        long long max_diff = r - l;

        // Calculate the maximum length using the quadratic formula
        long long n = (long long)(sqrt(2.0 * max_diff + 0.25) + 0.5);

        // Output the maximum length
        cout << n + 1 << endl;
    }

    return 0;
}
