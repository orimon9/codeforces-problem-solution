#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isPermutationPossible(int N, vector<int>& A) {
    // Initialize a set to keep track of required elements [1, N]
    unordered_set<int> required_elements;
    for (int i = 1; i <= N; ++i) {
        required_elements.insert(i);
    }

    // Iterate over the array A
    for (int i = 0; i < N; ++i) {
        // Find the element that should be at position i in C
        for (int j = 0; j < N; ++j) {
            int C_i = A[i] + j;
            if (C_i >= 1 && C_i <= N && required_elements.find(C_i) != required_elements.end()) {
                required_elements.erase(C_i);
                break;
            }
        }
    }

    // If all required elements are used, it means a permutation is possible
    return required_elements.empty();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        if (isPermutationPossible(N, A)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

