class Solution {
public:
    void solve(int index,int target,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums,int n)
    {
        if(index==n)
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(nums[index]<=target)
        {
            ds.push_back(nums[index]);
            solve(index,target-nums[index],ds,ans,nums,n);//pick
            ds.pop_back();
        }
        solve(index+1,target,ds,ans,nums,n);//not pick
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,ds,ans,nums,n);
        return ans;
    }
};