class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
       
        priority_queue<pair<int,int>> pq;   //max heap
        int n = nums.size();
       
        pq.push({nums[0], 0});
        int ans = nums[0];
        for (int i=1; i<n; i++){
           
            while(!pq.empty() && i-pq.top().second >k){
                pq.pop();
            }
            if (!pq.empty()){
                nums[i] += max(0,pq.top().first);
            }
           
            ans = max(ans,nums[i]);
            pq.push({nums[i],i});
        }
       return ans;
    }
};