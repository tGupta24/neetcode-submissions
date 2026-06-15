class Solution {
   public:
    vector<vector<int>> dp;
    int f(int amount, int n, vector<int>& coins) {
        // basecase
        if (n == 0) {
            if (amount == 0) return 0;
            return 1e9;
        }
        if (dp[amount][n] != -1) return dp[amount][n];
        int take = 1e9;
        if (amount - coins[n - 1] >= 0) {
            take = 1 + f(amount - coins[n - 1], n, coins);
        }
        int skip = f(amount, n - 1, coins);
        return dp[amount][n] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(amount + 1, vector<int>(n + 1, 0));
        // dp[0][0] = 0;
        for (int amt = 1; amt <= amount; amt++) {
            dp[amt][0] = 1e9;
        }
        for (int amt = 1; amt <= amount; amt++) {
            for (int N = 1; N <= n; N++) {
                int take = 1e9;
                if (amt - coins[N - 1] >= 0) {
                    take = 1 + dp[amt-coins[N - 1]][N];
                }
                int skip =dp[amt][N-1];
                dp[amt][N] = min(take, skip);
            }
        }

        int ans = dp[amount][n];
        if (ans == 1e9) return -1;
        return ans;
    }
};

// 1,5,10 -> unlimited

// target = 12

// f(12,1) => 1 + f(11,1)
//         => f(12,2)