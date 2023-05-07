class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>&nums) {
         vector<int> dp = {nums[0]};
        vector<int> res(nums.size(),0); 
        res[0] = 1;
        for(int i = 1; i<nums.size();++i){
            auto it = upper_bound(dp.begin(),dp.end(),nums[i]);
            if(it==dp.end()){
                dp.push_back(nums[i]); 
                res[i] = dp.size();
            }
            else{
                res[i] = it-dp.begin()+1;
                *it = nums[i];
            }
        }
        return res;
    }
};