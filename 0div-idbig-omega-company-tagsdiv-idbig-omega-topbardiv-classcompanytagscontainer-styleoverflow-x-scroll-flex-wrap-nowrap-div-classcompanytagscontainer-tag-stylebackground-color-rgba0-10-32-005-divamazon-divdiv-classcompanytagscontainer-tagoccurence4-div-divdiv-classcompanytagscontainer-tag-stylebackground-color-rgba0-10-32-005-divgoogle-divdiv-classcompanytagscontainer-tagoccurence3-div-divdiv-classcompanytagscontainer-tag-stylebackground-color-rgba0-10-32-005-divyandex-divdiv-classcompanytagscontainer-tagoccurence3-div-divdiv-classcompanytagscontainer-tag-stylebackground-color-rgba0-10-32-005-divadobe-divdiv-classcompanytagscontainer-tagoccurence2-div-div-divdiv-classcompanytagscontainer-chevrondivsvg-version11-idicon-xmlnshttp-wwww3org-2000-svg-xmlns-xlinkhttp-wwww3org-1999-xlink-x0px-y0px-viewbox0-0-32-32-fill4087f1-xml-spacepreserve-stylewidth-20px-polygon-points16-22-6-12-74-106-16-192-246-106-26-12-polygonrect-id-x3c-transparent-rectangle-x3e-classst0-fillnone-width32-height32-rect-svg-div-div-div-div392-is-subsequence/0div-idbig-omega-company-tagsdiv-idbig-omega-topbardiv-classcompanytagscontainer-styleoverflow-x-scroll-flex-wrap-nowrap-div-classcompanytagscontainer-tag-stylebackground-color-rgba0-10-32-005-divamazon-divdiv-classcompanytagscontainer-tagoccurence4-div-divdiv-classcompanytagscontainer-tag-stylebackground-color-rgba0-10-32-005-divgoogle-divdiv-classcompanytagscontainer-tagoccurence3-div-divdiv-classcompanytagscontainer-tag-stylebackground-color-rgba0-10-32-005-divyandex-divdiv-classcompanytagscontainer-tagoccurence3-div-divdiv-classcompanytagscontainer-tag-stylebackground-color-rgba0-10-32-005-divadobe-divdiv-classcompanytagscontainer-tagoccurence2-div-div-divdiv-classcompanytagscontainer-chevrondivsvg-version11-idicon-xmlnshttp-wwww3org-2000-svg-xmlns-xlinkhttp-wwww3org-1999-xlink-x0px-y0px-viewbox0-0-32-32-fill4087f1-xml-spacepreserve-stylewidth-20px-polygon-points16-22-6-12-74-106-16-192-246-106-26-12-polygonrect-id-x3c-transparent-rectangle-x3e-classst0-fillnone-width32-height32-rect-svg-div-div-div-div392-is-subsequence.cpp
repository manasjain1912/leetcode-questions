class Solution {
public:
      int dp[101][10001];
    int lcs(string &x, string &y,int n ,int m)
    {
       
        if(n==0 || m==0)
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
            return dp[n][m]= max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
        }
    
    }
    
    bool isSubsequence(string x, string y) {
       memset(dp,-1,sizeof(dp));
        int n=x.size();
        int m=y.size();
       if(lcs(x,y,n,m)==n)
       {
           return true;
       }
        else
        {
            return false;
        }
    }
};