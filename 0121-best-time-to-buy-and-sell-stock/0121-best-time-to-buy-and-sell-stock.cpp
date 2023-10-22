class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans=0;
     int n=prices.size();
        int temp=INT_MAX;
        for(int i=0;i<n;i++)
        {
         temp=min(temp,prices[i]);
            ans=max(ans,prices[i]-temp);
        }
        return ans;
    }
};