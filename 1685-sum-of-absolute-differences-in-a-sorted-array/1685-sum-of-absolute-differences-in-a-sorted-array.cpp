class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        vector<int> result;
        int leftsum=0;
        int rightsum=0;
        for(int i=0; i<nums.size(); i++){
            leftsum+=nums[i];
            rightsum=sum-leftsum;
            result.push_back(nums[i]*(i+1)-leftsum+rightsum-nums[i]*(nums.size()-1-i));
        }
        return result;
    }
};
