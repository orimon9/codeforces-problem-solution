#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    cin >> x;

    int t = 0; // Number of operations
    vector<int> n; // Stores the values of n for operation A

    while (x != 0 && t < 40) {
        int highest_bit = 31 - __builtin_clz(x); // Find the position of the highest set bit in x
        int ni = highest_bit; // Choose n as the highest set bit position
        n.push_back(ni);

        x ^= (1 << ni) - 1; // Perform operation A: x ⊕ (2^ni - 1)
        x++; // Perform operation B: increase x by 1

        t += 2; // Increment the number of operations by 2
    }

    // Output the number of operations
    cout << t << endl;

    // Output the values of n for operation A
    for (int i = 0; i < n.size(); ++i) {
        cout << n[i] << " ";
    }
    cout << endl;

    return 0;
}
