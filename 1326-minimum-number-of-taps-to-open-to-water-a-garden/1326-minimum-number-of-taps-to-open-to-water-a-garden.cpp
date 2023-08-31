class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int l = max(0, i - ranges[i]), r = min(i + ranges[i], n);
            for (int j = l; j <= r; j++) {
                dp[j] = min(dp[j], dp[l] + 1);
            }
        }
        return dp[n] == n + 1 ? -1 : dp[n];
    }
};