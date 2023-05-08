class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int sum=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j)
                {
                    sum+=mat[i][j];
                }
             if(i+j==n-1)
                {
                    sum+=mat[i][j];
                }
            }
        }
        if(n&1)
        {
            sum-=mat[n/2][n/2];
            return sum;
        }
        else
        {
            return sum;
        }
    }
};