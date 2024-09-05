#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(M);
        for (int i = 0; i < M; ++i) {
            cin >> A[i];
        }

        // Sort the array to prioritize colors with the most balls
        sort(A.begin(), A.end(), greater<int>());

        // Use a binary search on the number of boxes that can have exactly M balls
        int low = 0, high = N, mid, result = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            long long requiredBalls = 0;
            for (int i = 0; i < M; ++i) {
                requiredBalls += min(A[i], mid);
            }

            if (requiredBalls >= (long long) mid * M) {
                result = mid;  // We can fill at least 'mid' boxes with M balls
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Output the result for the current test case
        cout << result << endl;
    }

    return 0;
}
