t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    good_prefix_count = 0
    prefix_sum = 0
    prefix_sum_map = {}

    for i in range(n):
        prefix_sum += a[i]
        if prefix_sum == 2 * a[i] or (i > 0 and prefix_sum - 2 * a[i] in prefix_sum_map):
            good_prefix_count += 1
        prefix_sum_map[prefix_sum] = prefix_sum_map.get(prefix_sum, 0) + 1

    print(good_prefix_count)
