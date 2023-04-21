class Solution {
    const int MOD = 1e9 + 7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(minProfit+1, vector<int>(n+1));
        dp[0][0] = 1;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = minProfit; i >= 0; i--)
            for (int j = n-g; j >= 0; j--)
                (dp[min(i+p, minProfit)][j+g] += dp[i][j]) %= MOD;
        }
        int sum = 0;
        for (int i = 0; i <= n; i++)
            (sum += dp[minProfit][i]) %= MOD;
        return sum;
    }
};