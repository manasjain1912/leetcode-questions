class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        if(grid.size()==1)
            return 1;
        queue<pair<int,pair<int,int>>>q;
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        q.push({1,{0,0}});
  
        dist[0][0]=1;
        int rows[]={0,-1,+1,0,-1,-1,+1,+1};
        int cols[]={-1,0,0,+1,-1,+1,-1,+1};
        
        while(!q.empty())
        {
            auto it=q.front();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nrow=rows[i]+r;
                int ncol=cols[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dist[nrow][ncol]>1+dis)
                {
                    dist[nrow][ncol]=1+dis;
                   
                    if(nrow==n-1 && ncol==n-1)
                        return dis+1;
                         q.push({dis+1,{nrow,ncol}});
                    
                }
            }
        }
        
        return -1;  
    }
};