#include <iostream>
#include <vector>
#include <cstdint>

std::vector<int64_t> find_longest_sequence(int64_t n) {
    std::vector<int64_t> sequence;
    if (n == 1) {
        // Special case for n = 1
        sequence.push_back(1);
        return sequence;
    }

    sequence.push_back(1);
    int64_t current = 1;

    // Continuously add elements to the sequence until we reach n
    while (current != n) {
        int64_t next_val = current;
        // Check each bit up to 60 bits since 2^60 > 10^18
        for (int64_t bit = 0; bit < 60; ++bit) {
            int64_t test_val = next_val | (1LL << bit);
            if (test_val <= n && (current | test_val) == n) {
                next_val = test_val;
            }
        }
        if (current != next_val) {
            sequence.push_back(next_val);
            current = next_val;
        }
    }

    return sequence;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int64_t n;
        std::cin >> n;
        std::vector<int64_t> sequence = find_longest_sequence(n);
        std::cout << sequence.size() << std::endl;
        for (size_t i = 0; i < sequence.size(); ++i) {
            std::cout << sequence[i];
            if (i != sequence.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
