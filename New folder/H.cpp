#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> power(n);
    vector<int> school(n);

    for (int i = 0; i < n; ++i) {
        cin >> power[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> school[i];
    }

    vector<int> chosen(k);
    for (int i = 0; i < k; ++i) {
        cin >> chosen[i];
    }
    vector<int> finest_in_school(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        finest_in_school[school[i]] = max(finest_in_school[school[i]], power[i]);
    }

    int new_schools= 0;
    for (int i = 0; i < k; ++i) {
        int chosen_student_school = school[chosen[i] - 1];
        if (power[chosen[i] - 1] != finest_in_school[chosen_student_school]) {
            new_schools++;
        }
    }

    cout << new_schools << endl;

    return 0;
}
