#include <bits/stdc++.h>
#include <vector>
using namespace std;


using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate the sum of digits of a number
int digitSum(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to calculate the power of a number modulo MOD
long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;

        long long count = 0;
        for (int i = l; i < r; ++i) {
            long long n = power(10, i);
            int d_n = digitSum(n);
            long long kn = k * n;
            int d_kn = digitSum(kn);
            if (d_kn == k * d_n) {
                count++;
            }
        }

        cout << count % MOD << endl;
    }

    return 0;
}
