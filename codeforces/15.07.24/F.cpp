
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define MOD 998244353

using namespace std;

const long long fact(int n) {
  long long result = 1;
  for (int i = 2; i <= n; ++i) {
    result = (result * i) % MOD;
  }
  return result;
}

long long countPermutations(int n, const vector<int>& a, const vector<int>& b, const vector<int>& c) {
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);

  long long totalCost = 0;
  do {
    int prefixMax = 0, suffixMax = 0, ascents = 0;
    for (int i = 0; i < n; ++i) {
      if (p[i] > prefixMax) {
        prefixMax = p[i];
        ++suffixMax;
      }
      if (i > 0 && p[i] > p[i - 1]) {
        ++ascents;
      }
    }
    totalCost = (totalCost + (a[prefixMax] * b[suffixMax] % MOD) * c[ascents - 1] % MOD) % MOD;
  } while (next_permutation(p.begin(), p.end()));

  return totalCost * fact(n) % MOD;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n), c(n - 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    cin >> c[i];
  }

  long long result = countPermutations(n, a, b, c);
  cout << result << endl;

  return 0;
}
