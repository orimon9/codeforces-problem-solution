#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
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

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int m;
        cin >> m;
        vector<string> strings(m);

        for (int i = 0; i < m; ++i) {
            cin >> strings[i];
        }

        for (int i = 0; i < m; ++i) {
            string s = strings[i];
            if (s.length() != n) {
                cout << "NO\n";
                continue;
            }

            unordered_map<int, char> num_to_char;
            unordered_map<char, int> char_to_num;
            bool is_match = true;

            for (int j = 0; j < n; ++j) {
                int num = a[j];
                char ch = s[j];

                if (num_to_char.count(num) && num_to_char[num] != ch) {
                    is_match = false;
                    break;
                }
                if (char_to_num.count(ch) && char_to_num[ch] != num) {
                    is_match = false;
                    break;
                }

                num_to_char[num] = ch;
                char_to_num[ch] = num;
            }

            if (is_match) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

