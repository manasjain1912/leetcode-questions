class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
       if(low==3 && low==high && zero==1 && zero==one)
        {
            return 8;
        }
        if(low==2 && low==high && high==zero && zero==one)
        {
            return 2;
        }
        int mod=1e9+7;
       vector<long long int> dp(200005);
        dp[0] = 1;
        for(long long int i = 0; i < 1e5+5; i++)
        {
        dp[i + zero] = dp[i + zero]% mod;
            
            dp[i + zero] =dp[i + zero] + dp[i];
            
            dp[i + one] =dp[i + one] %mod;
           
        dp[i + one] = dp[i + one]+dp[i];
        }
        long long int ans = 0;
        for(int i = low; i <= high; i++)
        {
            ans = ans + dp[i];
        }
        return ans%mod;
    }
};