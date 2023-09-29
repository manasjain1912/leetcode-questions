class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2)
        {
            return true;
        }
        int counti=0;
        int countd=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<=nums[i])
            {
                counti++;
            }
            if(nums[i-1]>=nums[i])
            {
                countd++;
            }
        }
        if(counti==n-1 || countd==n-1)
        {
            return true;
        }
        return false;
    }
};