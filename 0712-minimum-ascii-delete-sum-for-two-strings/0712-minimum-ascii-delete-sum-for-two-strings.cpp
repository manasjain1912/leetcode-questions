class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1,string &s2,int i,int j)
    {
        int cost=0;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==s1.size() && j==s2.size())
        {
            cost=0;
        }
       else if(i==s1.size())
        {
            cost+=solve(s1,s2,i,j+1)+s2[j];
        }
       else if(j==s2.size())
        {
            cost+=solve(s1,s2,i+1,j)+s1[i];
        }
        else if(s1[i]==s2[j])
        {
            cost+=solve(s1,s2,i+1,j+1);
        }
        else
        {
          int  cost1=solve(s1,s2,i+1,j)+s1[i];
          int  cost2=solve(s1,s2,i,j+1)+s2[j];
            cost+=min(cost1,cost2);
        }
        return dp[i][j]=cost;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(s1,s2,0,0);
        return ans;
    }
};

	

	