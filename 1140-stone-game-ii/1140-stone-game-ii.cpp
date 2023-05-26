class Solution {
public:
    int dp[101][203][2];
    int helper(int node , int player ,  int M , vector<int>&piles)
    { 
        int ans = INT_MIN;
        if(node >= piles.size()) return 0;
        else if(dp[node][M][player]!=-1) return dp[node][M][player];
        if(player)
        {
            int take = 0;
            for(int i = node ; i < node + 2 * M and i < piles.size(); i++ )
            {
                take += piles[i];
                ans = max(ans , take + helper(i+1 , !player , max(M , i-node + 1) , piles)); 
            }
        }
        else
        {
            int take = 0;
            ans = INT_MAX;
            for(int i = node ; i < node + 2 * M and i < piles.size(); i++ )
            {
                ans = min (ans , helper(i + 1 , !player , max(M , i - node + 1 ) , piles ) );
            }
        }
        return dp[node][M][player] =  ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp , -1 , sizeof(dp));
        return helper(0 , true , 1 , piles);
    }
};