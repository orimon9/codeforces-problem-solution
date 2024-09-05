#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdlib> // for std::abs

using namespace std;

int main() {
    std::string S;
    std::cin >> S;

    int min_diff = std::numeric_limits<int>::max(); // Initialize min_diff with the maximum possible int value

    // Loop over all possible starting points for a substring of length 3
    for (int i = 0; i <= S.size() - 3; i++) {
        // Extract the substring from i to i+2 (inclusive), which is 3 characters long
        std::string substring = S.substr(i, 3);

        // Convert the substring to an integer
        int num = std::stoi(substring);

        // Calculate the absolute difference with 753
        int diff = std::abs(num - 753);

        // Update min_diff if the current difference is smaller
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    // Output the minimum difference
    std::cout << min_diff << std::endl;

    return 0;
}
