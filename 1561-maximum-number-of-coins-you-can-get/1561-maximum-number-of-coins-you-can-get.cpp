class Solution {
public:
    int maxCoins(vector<int>& piles) {
       int n=piles.size();
        sort(piles.begin(),piles.end());
        int sum=0;
         reverse(piles.begin(),piles.end());
        for(int i=0;i<n/3;i++)
        {
           piles.pop_back();
        }
         reverse(piles.begin(),piles.end());
        int temp=piles.size();
         for(int i=0;i<temp;i++)
        {
             if(i%2==0)
           sum+=piles[i];
        }
        return sum;
    }
};