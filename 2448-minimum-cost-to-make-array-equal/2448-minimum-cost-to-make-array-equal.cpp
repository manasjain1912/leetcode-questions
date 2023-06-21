class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long int n=nums.size();
        n=cost.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        long long int x=0;
        for(int i=0;i<n;i++){
            x=x+(long long int )v[i].second;
        }
        long long int total=0;
        long long int value;
        int i=0;
        while(total<(x+1)/2 && i<n){
            total=total+(long long int)v[i].second;
            value=v[i].first;
            i++;
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            nums[i]=abs(value-nums[i]);
            ans=ans+(long long int)nums[i]*(long long int)cost[i];

        }
        return ans;  
    }
};
