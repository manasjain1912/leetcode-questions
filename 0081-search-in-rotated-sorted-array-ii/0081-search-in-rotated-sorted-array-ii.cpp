class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                ans=true;
                break;
            }
        }
        return ans;
    }
};