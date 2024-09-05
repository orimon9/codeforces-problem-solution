#include <iostream>

using namespace std;

int minOperations(int n, int k) {
  // Edge case: if n is already 1, no operations needed
  if (n == 1) {
    return 0;
  }

  // Base case: if n is less than k, it's impossible
  if (n < k) {
    return -1;
  }

  // Calculate the minimum number of operations to reach 1 from n
  int operations = 0;
  while (n > 1) {
    // If n is divisible by k, we can directly convert it to 1 in one operation
    if (n % k == 0) {
      operations++;
      n = 1;
    } else {
      // Otherwise, we need to subtract k and increment operations
      n -= k;
      operations++;
    }
  }

  return operations;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int result = minOperations(n, k);
    if (result == -1) {
      cout << "Impossible" << endl;
    } else {
      cout << result << endl;
    }
  }

  return 0;
}
