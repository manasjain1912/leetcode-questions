class Solution {
public:
    int delrow[4] = {-1 , 0 , +1 , 0};
    int delcol[4] = {0 , -1 , 0 , +1};

    bool ispossible(int mid , vector<vector<int> > &cells , int row , int col){
        vector<vector<int> > mat(row , vector<int> (col , 0));
        for(int i=0 ; i<=mid ; i++){
            mat[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        vector<vector<int> > vis(row , vector<int> (col , 0));
        queue<pair<int ,int> > q;
        for(int j=0 ; j<col ; j++){
            if(mat[0][j] == 0){
                q.push({0 , j});
                vis[0][j]=1;
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0 ; i<4 ; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr>=0 && nc>=0 && nr<row && nc<col && mat[nr][nc]==0 && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    if(nr==row-1){
                        return true;
                    }
                    q.push({nr , nc});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int low = 0;
        int high = n-1;
        int res=0;
        while(low<=high){
            int mid =  low + (high-low)/2;
            if (ispossible(mid , cells , row , col)){
                res = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return res;
    }
};