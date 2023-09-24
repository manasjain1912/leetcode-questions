class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double temp_sum = 0;
        double dp[query_row+1][query_row+2];
        
        memset(dp,0,sizeof(dp));
        
        if(poured >= 1)
            dp[0][0] = poured;
        
        for(int i = 1; i <= query_row; i++)
        {
            temp_sum = 0;
            for(int j = 0; j <= i; j++)
            {
                temp_sum = (dp[i-1][j] > 1 ? (dp[i-1][j] - 1)/2.0:0);
                if(j >= 1)
                    temp_sum += (dp[i-1][j-1] > 1 ? (dp[i-1][j-1] - 1)/2.0:0);
                
                dp[i][j] = temp_sum;
            }
        }
        
        if(dp[query_row][query_glass] > 1)
            return 1;
        else
            return (dp[query_row][query_glass]);
    }
};