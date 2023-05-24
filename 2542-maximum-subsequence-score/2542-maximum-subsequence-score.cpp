class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>> pq;
        int n=nums1.size();
        for(int i=0;i<n;i++) pq.push({nums2[i],nums1[i]});
        priority_queue<int,vector<int>,greater<int>> min_heap;
        long long  curr_sum=0;
        int mini=1e9;
        long long ans=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            mini=p.first;
            curr_sum+=p.second;
            min_heap.push(p.second);
            if(min_heap.size()==k){
                ans=max(ans,mini*1LL*curr_sum);
            }
            if(min_heap.size()>k){
                curr_sum-=min_heap.top();
                min_heap.pop();
                ans=max(ans,mini*1LL*curr_sum);
            }
        }
        return ans;  
    }
};