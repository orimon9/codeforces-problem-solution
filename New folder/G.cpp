#include <iostream>
using namespace std;

int main() {
    int cnt1, cnt2, cnt3, cnt4;
    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;

    // Calculate the total number of opening and closing brackets needed
    int opening_brackets = cnt1 + cnt2;
    int closing_brackets = cnt3 + cnt4;

    // Check if the counts of opening and closing brackets match
    if (opening_brackets != closing_brackets) {
        cout << 0 << endl;
        return 0;
    }

    // Check if the count of opening brackets is always greater than or equal to the count of closing brackets
    if (cnt1 == 1 && cnt3 > 0) {
        cout << 0 << endl;
        return 0;
    }

    // If there's only one type of bracket, it's impossible to form a regular bracket sequence
    if (cnt1 == 1 || cnt3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;
    return 0;
}
