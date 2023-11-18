class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long n=nums.size();
        long i=0,sum=0,j;
        for(j=0;j<n;j++)
        {
            sum+=nums[j];
            if((j-i+1)*nums[j]-sum>k)
            {
                sum-=nums[i++];
            }
        }
        return j-i;
    }
};