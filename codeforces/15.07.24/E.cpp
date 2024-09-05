#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> left(n), right(n);
    stack<int> s;

    // Compute previous less
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack to reuse
    while (!s.empty()) s.pop();

    // Compute next less
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] > a[i])
            s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    vector<ll> f(n, 0);
    ll total_f = 0;

    // Calculate f(a)
    for (int i = 0; i < n; i++) {
        ll count = (ll)(i - left[i]) * (right[i] - i);
        f[i] = a[i] * count;
        total_f += f[i];
    }

    // Calculate results after removing each ai
    vector<ll> results(n);
    for (int i = 0; i < n; i++) {
        results[i] = total_f - f[i];
    }

    // Output results
    for (int i = 0; i < n; i++) {
        cout << results[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
