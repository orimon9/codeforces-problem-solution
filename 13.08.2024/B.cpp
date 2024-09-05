#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, bool> occupied;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool ok = true;

        for (int i = 0; i < n; ++i) {
            int seat = a[i];

            if (occupied.empty()) {

                occupied[seat] = true;
            } else {

                if (occupied[seat - 1] || occupied[seat + 1]) {
                    occupied[seat] = true;
                } else {
                    ok = false;
                    break;
                }
            }
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
