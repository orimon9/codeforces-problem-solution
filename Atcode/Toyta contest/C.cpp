#include<bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> L(N), R(N);
    vector<int> X(N);
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        X[i] = L[i];  // Start by selecting the lower bound
        sum += X[i];
    }

    if (sum == 0) {
        cout << "Yes\n";
        for (int x : X) {
            cout << x << " ";
        }
        cout << "\n";
        return 0;
    }

    // Adjust the values to make the sum zero
    for (int i = 0; i < N && sum != 0; i++) {
        if (sum > 0) {
            // Need to decrease the sum
            long long possible_decrease = min(sum, (long long)R[i] - X[i]);
            X[i] += possible_decrease;
            sum -= possible_decrease;
        } else {
            // Need to increase the sum
            long long possible_increase = min(-sum, (long long)X[i] - L[i]);
            X[i] -= possible_increase;
            sum += possible_increase;
        }
    }

    if (sum == 0) {
        cout << "Yes\n";
        for (int x : X) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
