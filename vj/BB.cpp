#include <iostream>
#include <vector>
using namespace std;

int generatePermutation(int n) {
    vector<int> result(n);
    if (n % 2 == 0) {
        int left = n / 2;
        int right = n;
        int index = 0;
        while (left > 0) {
            result[index++] = left--;
            result[index++] = right--;
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            result[i-1] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        generatePermutation(n);
    }

    return 0;
}
