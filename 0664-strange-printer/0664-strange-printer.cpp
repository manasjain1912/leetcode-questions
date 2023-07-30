class Solution {
public:
    int dp[105][105];
    int solve(string &s, int i, int j){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
       
        int x = i+1;
        while(x <= j && s[x] == s[i]){
          x++;
        }
         if(x==j+1)
         return 1;
        int ans = 1 + solve(s,x, j);  

        for(int k = x; k<=j; k++){
            if(s[k] == s[i]){
                ans = min(ans, solve(s,k,j) + solve(s,x, k-1));
            }
        }
        return dp[i][j] = ans;
    }
    
    int strangePrinter(string s) {
      memset(dp,-1,sizeof(dp));
       return solve(s,0,s.size()-1);
    }
};
