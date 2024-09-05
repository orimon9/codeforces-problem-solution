
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string a;
        cin >> a;

        unordered_map<char, int> problem_count;
        for (char problem : a) {
            problem_count[problem]++;
        }

        int needed_problems = 0;
        string required_levels = "ABCDEFG";

        for (char level : required_levels) {
            if (problem_count[level] < m) {
                needed_problems += m - problem_count[level];
            }
        }

        cout << needed_problems << endl;
    }

    return 0;
}
