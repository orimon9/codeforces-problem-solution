#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases

    while (t--) {
        int a, b;
        cin >> a >> b;  // Read a and b for each test case

        // Check if the sum a + 2 * b is even
        if ((a + 2 * b) % 2 == 0) {
            cout << "YES" << endl;  // It is possible to make the sum zero
        } else {
            cout << "NO" << endl;   // It is not possible to make the sum zero
        }
    }

    return 0;
}
