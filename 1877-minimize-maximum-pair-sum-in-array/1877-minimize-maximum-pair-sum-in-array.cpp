class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum = 0;
        int sub=0;
        for(int i=0; i<n/2; i++)
        {
            int sub = nums[i] + nums[n-1-i];
            if(sum < sub)
                sum = sub;
        }
        
        return sum;
    }
};
