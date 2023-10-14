class Solution {
    int dfs(int i, int left, int n, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp) {
        if(left <= 0) return 0;
        if(i == n) return 1e9;
        if(dp[i][left] != -1) return dp[i][left];
        
        int notpick = dfs(i + 1, left, n, cost, time, dp);
        int pick = cost[i] + dfs(i + 1, left - time[i] - 1, n, cost, time, dp);
        
        return dp[i][left] = min(pick, notpick);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(0, n, n, cost, time, dp);
    }
};