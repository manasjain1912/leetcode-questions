class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[slow];
        int fast=nums[fast];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};