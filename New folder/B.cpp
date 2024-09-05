#include <bits/stdc++.h>
using namespace std;
using namespace std;

bool canFormSquare(long long n, long long s) {
    long long requiredBlocks = s * s;
    long long currentSum = 0;
    for (long long i = 1; i <= n; ++i) {
        currentSum += (i + 1) / 2;
        if (currentSum >= requiredBlocks) {
            return true;
        }
        if (i > s * 2) {
            break;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long left = 0, right = n, maxSide = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canFormSquare(n, mid)) {
                maxSide = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << maxSide << endl;
    }

    return 0;
}
