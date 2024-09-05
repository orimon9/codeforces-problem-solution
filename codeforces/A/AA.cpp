#include <iostream>
using namespace std;

bool isPossible(int x1, int y1, int x2, int y2) {
    // Calculate the difference in goals for both teams
    int dx = x2 - x1;
    int dy = y2 - y1;

    // If the difference between x1 and x2 is not equal to the difference between y1 and y2,
    // or one of the differences is zero, then it's possible they never had an equal score.
    return abs(dx - dy) <= 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (isPossible(x1, y1, x2, y2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
