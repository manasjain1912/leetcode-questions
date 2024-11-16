class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return nums;
        vector<int> ans(n - k + 1, -1);
        int i = 0;
        int j = k-1;
        while(j < n){
            for(int ind = i+1 ; ind <= j ; ind++){
                if(nums[ind] == nums[ind-1] + 1){
                    ans[i] = max(ans[i], nums[ind]);
                }
                else{
                    ans[i] = -1;
                    break;
                }
            }
            i++;
            j++;
        }
        return ans;
    }
};