class Solution {
public:
    int dp[1002][1002];
    int isPal(string s,int i,int j) { 
        if(i>=j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j])
            return dp[i][j] = 0;
        return dp[i][j] = isPal(s,i+1,j-1);
    }
    int countSubstrings(string s) {
     int ans = 0;
    memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.length();i++) {
            for(int j=i;j<s.length();j++) {
                if(isPal(s,i,j)) ans++;
            }
        }
        return ans;
    }
};