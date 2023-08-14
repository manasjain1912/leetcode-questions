class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxhp;
        for(auto it:nums)
        {
            maxhp.push(it);
        }
        while(k>1)
        {
            maxhp.pop();
            k--;
        }
        return maxhp.top();
    }
};