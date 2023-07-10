class Solution {
public:
    void solve(int index,vector<int>nums,vector<int>&ds,vector<vector<int>>&ans)
    {
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++)
        {
            if(i!=index && nums[i-1]==nums[i]) continue;
            ds.push_back(nums[i]);
            solve(i+1,nums,ds,ans);
            ds.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>ds;
        solve(0,nums,ds,ans);
        return ans;
    }
};