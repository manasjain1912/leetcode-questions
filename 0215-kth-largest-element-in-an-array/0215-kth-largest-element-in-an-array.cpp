class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //remove k-1 elements from maxheap
        priority_queue<int>pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        while(k>1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};