class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st;
        int curr_min = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            while (!st.empty() && nums[i] >= st.top().first) {
                st.pop();
            }
            
            if (!st.empty() && nums[i] > st.top().second) {
                return true;
            }
            
            curr_min = min(nums[i], curr_min);
            st.push(make_pair(nums[i], curr_min));
        }
        
        return false;

    }
};