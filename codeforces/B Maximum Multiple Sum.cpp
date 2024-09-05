#include <bits/stdc++.h>
using namespace std;


int total(int x, int n) {
    int sum = 0;
    for (int i = 1; i * x <= n; ++i) {
        sum += i * x;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        int possible_x = 2;
        int max_sum = total(2, n);

        for (int x = 3; x <= n; ++x) {
            int curnt_sum = total(x, n);
            if (curnt_sum > max_sum) {
                max_sum = curnt_sum;
                possible_x = x;
            }
        }

        cout << possible_x << endl;
    }

    return 0;
}
