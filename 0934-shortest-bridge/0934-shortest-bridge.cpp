class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        long res=INT_MAX;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j])
                {
                    fun(grid,i,j); // dfs
                    return bfs(grid,vis);
                }
        return 0;
    }
    void fun(vector<vector<int>>& v,int i,int j)
    {
        if(i<0 || j<0 || i>=v.size() || j>=v.size() || v[i][j]!=1)
            return;
        
        v[i][j]=2;
        
        fun(v,i+1,j);
        fun(v,i,j+1);
        fun(v,i-1,j);
        fun(v,i,j-1);
    }
    int bfs(vector<vector<int>>& v,vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;
        for(int i=0;i<v.size();i++)
            for(int j=0;j<v.size();j++)
                if(v[i][j]==1)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
        
        int res=0;
        while(!q.empty())
        {
           int t=q.size();
           for(int i=0;i<t;i++)
           {               
               auto x=q.front();
               q.pop();        
               
               if(v[x.first][x.second]==2)
                   return res-1;
            
               if(valid(v,vis,x.first+1,x.second))
                   q.push({x.first+1,x.second});
               
               if(valid(v,vis,x.first-1,x.second))
                   q.push({x.first-1,x.second});
               
               if(valid(v,vis,x.first,x.second-1))
                   q.push({x.first,x.second-1});
               
               if(valid(v,vis,x.first,x.second+1))
                   q.push({x.first,x.second+1});
           }
           res++;
        }
        return res;
    }
    int valid(vector<vector<int>>& v,vector<vector<int>>& vis,int i,int j)
    {
        if(i<0 || j<0 || i>=v.size() || j>=v.size() || v[i][j]==1 || vis[i][j])
            return 0;
       return vis[i][j]=1;
    }
};