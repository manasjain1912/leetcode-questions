class Solution {
public:
    int dp[501][501];
    int lcs(string &x,string &y,int n,int m)
    {
        if(m==0 || n==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(x[n-1]==y[m-1])
        {
            return dp[n][m]=1+lcs(x,y,n-1,m-1);
        }
        else
        {
            return dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
        }
    }
    int minInsertions(string x) {
         memset(dp,-1,sizeof(dp));
         int n=x.size();
        string y=x;
        reverse(y.begin(),y.end());
        int m=y.size();
        return m - lcs(x,y,n,m);
    }
};