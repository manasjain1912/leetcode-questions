class Solution {
public:
    
    void solve(int src, vector<int> &vis, vector<int> adj[]){
        
        vis[src] = 1;
        for(auto i: adj[src]){
            if(!vis[i]){
                solve(i, vis, adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<isConnected[i].size(); j++){
                
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
                
            }
        }
        vector<int> vis(n, 0);
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                solve(i, vis, adj);
                count++;
            }
        }
        return count;
    }
};