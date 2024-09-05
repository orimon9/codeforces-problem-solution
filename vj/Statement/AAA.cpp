#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int a, b;
        cin >> a >> b;  // Read a and b for each test case

        // Calculate the total sum of the array
        int total = a + 2 * b;

        // Check if the total is even
        if (total % 2 == 0) {
            cout << "YES" << endl;  // It is possible to make the sum zero
        } else {
            cout << "NO" << endl;   // It is not possible to make the sum zero
        }
    }

    return 0;
}
