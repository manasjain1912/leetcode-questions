class Solution {
public:
    int rec(vector<int>&nums,int prev,int ind, int n,vector<vector<int>>&dp)
    {
        if(ind==n)
            return 0;
        if(dp[prev+1][ind]!=-1)
            return dp[prev+1][ind];
        int len=0+rec(nums,prev,ind+1,n,dp);//not take
        if(prev==-1 || nums[ind]>nums[prev])
        {
            len=max(len,1+rec(nums,ind,ind+1,n,dp));//take
        }
        return dp[prev+1][ind]=len;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return rec(nums,-1,0,n,dp);
        
    }
};