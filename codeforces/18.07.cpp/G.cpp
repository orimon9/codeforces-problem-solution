#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to convert a binary string to a decimal integer
int binaryToDecimal(const string& binary) {
    int decimal = 0;
    for (char bit : binary) {
        decimal = (decimal << 1) + (bit - '0');
    }
    return decimal;
}

// Function to convert a decimal integer to a binary string of fixed length
string decimalToBinary(int decimal, int length) {
    string binary(length, '0');
    for (int i = length - 1; i >= 0; --i) {
        binary[i] = (decimal & 1) ? '1' : '0';
        decimal >>= 1;
    }
    return binary;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int target = binaryToDecimal(s);
        vector<int> ai(n);
        for (int i = 0; i < n; ++i) {
            ai[i] = binaryToDecimal(a[i]);
        }

        // Attempt to find a suitable x
        int x = 0;
        for (int bit = 0; bit < k; ++bit) {
            int bitPosition = 1 << bit;
            int bitSum = 0;
            for (int number : ai) {
                bitSum += (number & bitPosition) ? 1 : 0;
            }
            if ((bitSum % 2) != ((target & bitPosition) ? 1 : 0)) {
                x |= bitPosition;  // Toggle this bit in x
            }
        }

        // Validate the result by recalculating the XOR sum
        int checkSum = 0;
        for (int number : ai) {
            checkSum += number ^ x;
        }

        if (checkSum == target) {
            cout << decimalToBinary(x, k) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
