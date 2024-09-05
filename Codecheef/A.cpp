#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string> cases(T);

    for (int i = 0; i < T; ++i) {
        cin >> cases[i];
    }

    for (const auto& S : cases) {
        int n = S.size();
        long long count = 0;

        // Calculate the number of valid partitions
        // We need to find all the valid positions where we can split S into P, Q, and R.
        // Iterate over possible positions of P.
        vector<int> prefixCount(n+1, 0);

        // Counting the frequency of each prefix
        for (int i = 1; i <= n; ++i) {
            prefixCount[i] = prefixCount[i-1] + (S[i-1] == S[n-i]);
        }

        // Summing the valid splits
        for (int i = 1; i < n; ++i) {
            if (prefixCount[i] == prefixCount[n-i]) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
