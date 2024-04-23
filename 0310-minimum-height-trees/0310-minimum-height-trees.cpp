class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<vector<int> > adj(n, vector<int>());
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> leaves;
        for(int i = 0;i<n;i++){
            if(adj[i].size() == 1){
                leaves.push_back(i);
            }
        }
        
        while(n>2){
            n-=leaves.size();
            vector<int> newleaves;
            for(int i: leaves){
                int j = adj[i].back();
                adj[j].erase(std::remove(adj[j].begin(), adj[j].end(), i), adj[j].end());
                if(adj[j].size()==1)newleaves.push_back(j);
            }
            leaves = newleaves;
        }
        return leaves;
    }
};