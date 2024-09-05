#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long hash_aa, hash_yb;

        cout << "? aa" << endl;
        cout.flush();
        cin >> hash_aa;

        cout << "? yb" << endl;
        cout.flush();
        cin >> hash_yb;


        long long p = 31;
        long long m = 59;

        cout << "! " << p << " " << m << endl;
        cout.flush();
    }
    return 0;
}
