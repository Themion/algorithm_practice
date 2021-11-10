def solution(N):
    global dp
    # dp[N][start]: N개의 블록 중 가장 높은 단을 start개를 사용
    dp = [[0 for _ in range(i + 1)] for i in range(N + 1)]
    ans = 0

    dp[1][1] = dp[2][2] = 1

    for n in range(3, N + 1, 1):
        for start in range(n - 1, 1, -1):
            for start_ in range(len(dp[n - start])):
                if start <= start_: break
                dp[n][start] += dp[n - start][start_]

        dp[n][n] += 1

    for i in range(n): ans += dp[N][i]

    return ans