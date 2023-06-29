class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int totalKeys=0;
        // pair<<x, y> , key>
        queue<tuple<int,int,int>> q;
        vector<vector<vector<int>>> V(row, vector<vector<int>>(col, vector<int>(64, 0)));
        int sx, sy, key, steps=0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                char ch = grid[i][j];
                if(ch == '@') {
                    sx = i;
                    sy = j;
                    key = 0;
                    V[i][j][key] = 1;
                }
                if(ch >= 'a' && ch <= 'f') {
                    totalKeys |= (1 << (ch - 'a'));
                }
            }
        }

        q.push({sx, sy, key});
        vector<vector<int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()) {
            int qSize = q.size();
            while(qSize--) {
                auto [cx, cy, ck] = q.front();
                q.pop();
                
                if(ck == totalKeys) return steps;

                for(vector dir: direction) {
                    int nx, ny, nk;
                    nx = cx + dir[0];
                    ny = cy + dir[1];
                    nk = ck;

                    if(nx<0 || nx>=row || ny<0 || ny>=col || grid[nx][ny] == '#' || V[nx][ny][nk])
                        continue;
                    
                    int nCh = grid[nx][ny];

                    if(nCh >= 'A' && nCh <= 'F' && !(nk >> (nCh - 'A') & 1)) continue;

                    if(nCh >= 'a' && nCh <= 'f') {
                        nk |= (1 << (nCh - 'a'));
                    }
                    
                    V[nx][ny][nk] = 1;

                    q.push({nx, ny, nk});
                }                
            }
            steps++;
        }

        return -1;
    }
};