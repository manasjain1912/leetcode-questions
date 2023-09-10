class Solution {
public:
    void solve(int index,int target,vector<int>nums,vector<int>ds,vector<vector<int>>&ans)
    {
        if(index==nums.size())
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
            solve(index,target-nums[index],nums,ds,ans);//pick
            ds.pop_back();
        }
          solve(index+1,target,nums,ds,ans);//not pick
     
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,target,nums,ds,ans);
        return ans;
    }
};