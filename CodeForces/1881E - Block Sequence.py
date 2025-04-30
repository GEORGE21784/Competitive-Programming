t = int(input())
for _ in range(t):
    n = int(input())
    a = [0]+[int(x) for x in input().split()]
    dp = [0] * (n+2)
    for i in range(n, 0, -1):
        mn = 10**18
        if i + a[i] <= n:
            mn = dp[i + a[i] + 1]
        dp[i] = min(dp[i+1] + 1, mn)
    print(dp[1])