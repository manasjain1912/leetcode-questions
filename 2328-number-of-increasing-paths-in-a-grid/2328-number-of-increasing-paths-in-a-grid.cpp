class Solution {
public:
    int mod=1e9+7;
    vector<pair<int,int>> dir = {{0,1},{-1,0},{1,0},{0,-1}};
    
    bool isValid(int i,int j,int n,int m){
        return (i>=0 and i<n and j>=0 and j<m);
    
    }
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int n=grid.size(),m=grid[0].size();
        long long ans=1;
        for(int d=0;d<4;d++){
            int newx=i+dir[d].first;
            int newy=j+dir[d].second;
            
            if(isValid(newx,newy,n,m) and grid[newx][newy]>grid[i][j]){
                ans+= f(newx,newy,grid,dp);
                ans%=mod;
            }
        }        
        return dp[i][j]=ans;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=f(i,j,grid,dp);
                sum%=mod;
            }
        }
        return sum%mod;
    }
};