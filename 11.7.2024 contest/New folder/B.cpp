#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        int numOnes = 0;

        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            if (a[i] == 1) {
                numOnes++;
            }
        }


        int requiredMerges = k - 1;

        if (numOnes >= requiredMerges) {

            cout << requiredMerges << endl;
        } else {

            int additionalOnesNeeded = requiredMerges - numOnes;
            cout << requiredMerges + additionalOnesNeeded << endl;
        }
    }
    return 0;
}
