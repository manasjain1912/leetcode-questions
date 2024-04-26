class Solution {
public:
    int ans = INT_MAX;
    
    int dp[201][201] = {0};
    int D[201][201];
    int helperMinFallingPathSum(int r, vector<vector<int>>& arr, int prevcol)
    {
        if(r == arr.size())
            return 0;
        
        if(D[r][prevcol] != -1)
            return D[r][prevcol];
        
        int temp=INT_MAX;
        
        for(int j=0; j<arr.size(); j++)
        {
            if((r==0) or (r>0 and dp[r-1][j] == 0))
            {
                dp[r][j] = 1;
                temp = min(temp, arr[r][j] +  helperMinFallingPathSum(r+1, arr, j));
                dp[r][j] = 0;
            }
        }
        
        D[r][prevcol] = temp;
        return temp;
    }
    
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        memset(D, -1, sizeof(D));
        return helperMinFallingPathSum(0, arr, 0);
       
    }
};