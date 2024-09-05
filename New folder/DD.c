#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long max_x = 0;
    long long max_y = 0;

    for (int i = 0; i < n; ++i) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        if (x > max_x) max_x = x;
        if (y > max_y) max_y = y;
    }

    // The minimum length of the shorter side of the triangle
    long long min_side_length = max_x > max_y ? max_x : max_y;
    printf("%lld\n", min_side_length);

    return 0;
}
