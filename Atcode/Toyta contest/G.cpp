#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> buildLPS(const string& pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int countMatches(const string& text, const string& pattern) {
    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;
    int count = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++, j++;
        }
        if (j == pattern.size()) {
            count++;
            j = lps[j - 1];
        } else if (i < text.size() && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int Q;
    cin >> Q;

    while (Q--) {
        string T;
        cin >> T;
        cout << countMatches(S, T) << '\n';
    }

    return 0;
}
