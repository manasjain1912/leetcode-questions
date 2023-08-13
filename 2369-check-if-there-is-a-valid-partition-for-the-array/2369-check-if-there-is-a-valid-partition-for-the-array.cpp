class Solution {
public:
bool dfs(vector<int> &nums,int n,int i,vector<int>& dp){
    if(i>=n)return true;
    bool ans1=false,ans2=false;
    if(dp[i]!=-1)return dp[i];
    if(i+2<n){
        if(nums[i]==nums[i+1] && nums[i]==nums[i+2]){
            ans1= dfs(nums,n,i+3,dp);
        }
        else if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
            ans1= dfs(nums,n,i+3,dp);
        }
    }
    if(i+1<n){
        if(nums[i]==nums[i+1]){
            ans2= dfs(nums,n,i+2,dp);
        }   
    }
    return dp[i]=ans1||ans2;
}
bool validPartition(vector<int>& nums) {
    int idx=0,n=nums.size();
    vector<int> dp(n+1,-1);
    return dfs(nums,n,idx,dp);
}
};