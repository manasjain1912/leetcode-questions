class Solution {
private:
    int f(int i, int prev, string &s, int &n, int &k, vector<vector<int>> &dp)
    {
        if(i == n) return 0;
        
        if(dp[i][prev] != -1)
            return dp[i][prev];
        
        
        int notPick = f(i+1, prev, s, n, k, dp);
        
        int pick = 0;
        
    
        if(prev == 0 || abs(prev - (s[i] - 'a' + 1)) <= k)
            pick = 1 + f(i+1, s[i] - 'a' + 1, s, n, k, dp);
        
    
        return dp[i][prev] = max(pick, notPick);
    }
    
public:
    int longestIdealString(string s, int k) {
        
        int n = s.size();
        
        vector<vector<int>> dp(n+1, vector<int>(27, -1));

        
        return f(0, 0, s, n, k, dp);
    }
};