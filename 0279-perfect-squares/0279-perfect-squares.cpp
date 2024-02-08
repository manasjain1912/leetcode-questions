class Solution{
	public:
	int numSquares(int n)
	{
        vector<int> dp(n+1);
        
        if(n <= 3)      
            return n; 
        
        int i = 0;
        while(i <= n){
            dp[i] = i;   
            
            for(int j=1; j*j <= i; j++)    
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            
            i++;
        }
         
        return dp[n];
	}
};