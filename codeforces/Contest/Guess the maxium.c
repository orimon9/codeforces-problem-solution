#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int* a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        // Sort the array
        qsort(a, n, sizeof(int), compare);

        // The maximum integer k at which Alice is guaranteed to win
        // is the second last element in the sorted array
        int k = a[n - 2];
        printf("%d\n", k);

        free(a);
    }

    return 0;
}
