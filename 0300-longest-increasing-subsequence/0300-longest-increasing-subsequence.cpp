class Solution {
public:
    int solve(int prev_index,int index,vector<int>&nums,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(index==n) return 0;
        if(dp[index][prev_index+1]!=-1)
        {
            return dp[index][prev_index+1];
        }
       int len= solve(prev_index,index+1,nums,dp);//not pick
        if(prev_index==-1 ||  nums[index]>nums[prev_index])
        {
          len= max(len,1+solve(index,index+1,nums,dp));
        }
        return dp[index][prev_index+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(-1,0,nums,dp);
    }
};