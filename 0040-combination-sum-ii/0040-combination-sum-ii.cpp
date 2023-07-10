class Solution {
public:
    void solve(int index,int target,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,int n)
    {
        
            if(target==0)
            {
                ans.push_back(ds);
                 return;
            }
           
        
        for(int i=index;i<n;i++)
        {
            if(i!=index && nums[i]==nums[i-1])continue;
            if(nums[i]>target)
                break;
            ds.push_back(nums[i]);
            solve(i+1,target-nums[i],nums,ds,ans,n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>ds;
        int n=nums.size();
        solve(0,target,nums,ds,ans,n);
        return ans;
    }
};
