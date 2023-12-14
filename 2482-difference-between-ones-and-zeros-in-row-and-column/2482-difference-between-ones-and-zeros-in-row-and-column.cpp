class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<int>countrow0(n);
         vector<int>countrow1(n);
        vector<int>countcol0(m);
         vector<int>countcol1(m);
        for(int i=0;i<n;i++)
        {
            int cntrow0=0,cntrow1=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                cntrow0++;
                }
                if(grid[i][j]==1)
                {
                cntrow1++;
                }
            }
            countrow0[i]=cntrow0;
            countrow1[i]=cntrow1;
        }
         for(int i=0;i<m;i++)
        {
             int cntcol0=0,cntcol1=0;
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==0)
                {
                cntcol0++;
                }
                if(grid[j][i]==1)
                {
                cntcol1++;
                }
            }
            countcol0[i]=cntcol0;
            countcol1[i]=cntcol1;
         }
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 ans[i][j]=countrow1[i] + countcol1[j] - countrow0[i] - countcol0[j];
             }
         }
        return ans;
        
    }
};

