#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    char prev = 0;

    for (char c : s) {
        if (c == prev) {
            cnt++;
            prev = 0; // reset prev to 0 to avoid deleting consecutive equal letters
        } else {
            prev = c;
        }
    }

    if (cnt % 2 == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
