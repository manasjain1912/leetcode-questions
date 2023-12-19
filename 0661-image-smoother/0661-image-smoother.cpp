class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n= img.size(); 
        int m= img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        int dx[8]= {1,1,1,-1,-1,-1,0,0};
        int dy[8]= {-1,1,0,-1,0,1,-1,1};
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int cnt=1, sum=img[i][j];
                for (int it=0; it<8; it++){
                    int nr= dx[it]+i;
                    int nc= dy[it]+j;
                    if (nr>=0 && nr<n && nc>=0 && nc<m){
                        sum+= img[nr][nc];
                        cnt++;
                    }
                }
                ans[i][j]= sum/cnt;
            }
        }
        return ans;
    }
};
