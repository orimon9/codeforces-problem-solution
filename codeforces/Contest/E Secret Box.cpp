#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int countPositions(int x, int y, int z, int a, int b, int c) {
    return (x - a + 1) * (y - b + 1) * (z - c + 1);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, z;
        long long k;
        cin >> x >> y >> z >> k;

        int max_positions = 0;

        for (int a = 1; a <= min(x, (int)cbrt(k)); ++a) {
            if (k % a != 0) continue;
            long long remaining_k = k / a;

            for (int b = 1; b <= min(y, (int)sqrt(remaining_k)); ++b) {
                if (remaining_k % b != 0) continue;
                int c = remaining_k / b;

                if (c > 0 && c <= z) {
                    int positions = countPositions(x, y, z, a, b, c);
                    max_positions = max(max_positions, positions);
                }
            }
        }

        cout << max_positions << endl;
    }

    return 0;
}
