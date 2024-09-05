#include <stdio.h>

// Function to calculate the digital root of a number
int digitalRoot(int n) {
    return (n - 1) % 9 + 1;
}

// Function to find the k-th positive number with a given digital root
long long findKthNumber(int k, int x) {
    // The k-th number with digital root x is the smallest number with digital root x
    // multiplied by k
    return (k - 1) * 9 + x;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int k, x;
        scanf("%d %d", &k, &x);

        // Find the k-th positive number with digital root x
        long long ans = findKthNumber(k, x);
        printf("%lld\n", ans);
    }

    return 0;
}
