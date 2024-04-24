class Solution {
public:
    int dp[38];
    int recursion(int n)
    {
        if(n==0)
        {
            return dp[n]=0;
        }
        if(n==1 || n==2)
        {
            return dp[n]=1;
        }
         if(dp[n]!=-1)
         {
             return dp[n];
         }
        else
        {
            return dp[n]=recursion(n-3)+recursion(n-2)+recursion(n-1);
        }
    }
    int tribonacci(int n) 
    {
        memset(dp,-1,sizeof(dp));
      return recursion(n);
    }
};
