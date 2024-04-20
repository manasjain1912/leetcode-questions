class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int x = i;
                    int y = j;
                    bfs(x,y,vis,grid);
                    ans.push_back({i,j,x,y});
                }
            }
        }
        return ans;
    }
    
    void bfs(int &i, int &j, vector<vector<int>>& vis,vector<vector<int>> &grid){
        
        int m = grid.size();
        int n = grid[0].size();
        int drows[] = {-1,0,1,0};
        int dcols[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            
            for(int k=0;k<4;k++){
                int nrow = row + drows[k];
                int ncol = col + dcols[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                    if(nrow > i)
                        i = nrow;
                    if(ncol > j)
                        j = ncol;
                }
            }
        }
    }
};