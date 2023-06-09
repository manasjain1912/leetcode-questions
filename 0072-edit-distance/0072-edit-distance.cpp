class Solution {
public:
    int rec(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(i<0)
        {
            return j+1;
        }
        if(j<0)
        {
            return i+1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            return dp[i][j]=rec(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=1+min(rec(i-1,j,s1,s2,dp), min(rec(i,j-1,s1,s2,dp),rec(i-1,j-1,s1,s2,dp)));
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return rec(n-1,m-1,s1,s2,dp);
    }
};