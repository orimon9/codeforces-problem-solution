#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countGoodPrefixes(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> prefixSums; // Map to store frequencies of prefix sums
    int goodPrefixes = 0;
    int prefixSum = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += arr[i];
        if (prefixSum == 0 || prefixSums.count(prefixSum) > 0) {
            ++goodPrefixes;
            prefixSums.clear(); // Reset prefix sums map as we found a good prefix
            prefixSum = 0; // Reset prefix sum
        } else {
            prefixSums[prefixSum] = 1;
        }
    }

    return goodPrefixes;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << countGoodPrefixes(arr) << endl;
    }

    return 0;
}
