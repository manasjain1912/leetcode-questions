class Solution {
public:
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        vector<vector<int>> dp(loc.size(),vector<int>(fuel+1,-1));
       return solution(loc,start,finish,fuel,dp);
        
    }
    int solution(vector<int>& loc,int start,int finish,int fuel, vector<vector<int>>& dp){
        if(fuel<0)
        return 0;
        int mod=1e9+7;
        if(dp[start][fuel]!=-1)
        return dp[start][fuel];
        int sum=0;
        if(start==finish)
        sum=1;
        for(int i=0;i<loc.size();i++)
        {
            if(i!=start)
            {
                sum=(sum+solution(loc,i,finish,fuel-abs(loc[start]-loc[i]),dp))%mod;
            }

        }
        return dp[start][fuel]=sum;
    }
};