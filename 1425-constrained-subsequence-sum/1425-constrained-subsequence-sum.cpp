class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
       deque<pair<int,int>>que;

       int ans=-1e4;
       for(int i=nums.size()-1;i>=0;i--){
         
         while(!que.empty() && que.front().second>i+k) que.pop_front();

         if(que.empty()){
             if(nums[i]>0){
                 que.push_back({nums[i],i});
             }
             ans=max(ans,nums[i]);
         }
         else{
             int sum=nums[i]+que.front().first;
             if(sum>0){
                 while(!que.empty() && que.back().first<=sum)que.pop_back();
                 que.push_back({sum,i});
                 ans=max(ans,sum);
             }
         }


       }
       return ans;

    }
};