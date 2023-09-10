class Solution {
public:
     void solve(int index,vector<int>nums,vector<int>ds,vector<vector<int>>&ans)
    {
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++)
        {
            ds.push_back(nums[i]);
            solve(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
        vector<int>ds;
        solve(0,nums,ds,ans);
        return ans;  
    }
};