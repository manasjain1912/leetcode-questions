class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>odd;
        vector<int>even;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        for(int i=0;i<even.size();i++)
        {
            ans.push_back(even[i]);
        }
         for(int i=0;i<odd.size();i++)
        {
            ans.push_back(odd[i]);
        }
        return ans;
    }
};