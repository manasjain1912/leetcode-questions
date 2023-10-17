class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
            }
            if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
            }
        }
        vector<int> parent(n, -1);
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                if(parent[leftChild[i]] != -1)
                    return false;
                parent[leftChild[i]] = i;
            }
            if(rightChild[i] != -1){
                if(parent[rightChild[i]] != -1)
                    return false;
                parent[rightChild[i]] = i;
            }
        }
        int count = 0;
        int node = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == -1){
                node = i;
                count++;
            }
        }
        if(!count || count > 1)
            return false;
        queue<int> q;
        q.push(node);
        vector<bool> vis(n, 0);
        vis[node] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(vis[it] == 1)
                    return false;
                vis[it] = 1;
                q.push(it);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i])
                return false;
        }
        return true; 
    }
};