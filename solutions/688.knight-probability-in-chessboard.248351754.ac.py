class Solution(object):
    def knightProbability(self, N, K, r, c):
        dp = [[0] * N for _ in xrange(N)]
        dp[r][c] = 1
        for _ in xrange(K):
            dp2 = [[0] * N for _ in xrange(N)]
            for r, row in enumerate(dp):
                for c, val in enumerate(row):
                    for dr, dc in ((2,1),(2,-1),(-2,1),(-2,-1),
                                   (1,2),(1,-2),(-1,2),(-1,-2)):
                        if 0 <= r + dr < N and 0 <= c + dc < N:
                            dp2[r+dr][c+dc] += val / 8.0
            dp = dp2

        return sum(map(sum, dp))


