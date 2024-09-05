def solve():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        operations = []

        for _ in range(n):
            a, b = map(int, input().split())
            for j in range(1, min(a, b) + 1):
                operations.append(min(a * j, b * j))

        operations.sort()

        if len(operations) < k:
            print(-1)
        else:
            print(sum(operations[:k]))

# Reading input and solving the problem
solve()
