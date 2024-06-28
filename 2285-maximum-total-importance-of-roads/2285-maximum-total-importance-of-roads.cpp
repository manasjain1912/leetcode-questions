class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
            vector<int> adj(n,0);  
        for(auto &it:roads){
            adj[it[0]]++; adj[it[1]]++;
        }
        sort(adj.begin(),adj.end()); 
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans+=adj[i]*1LL*(i+1); 
        }
        return ans;
    }
};