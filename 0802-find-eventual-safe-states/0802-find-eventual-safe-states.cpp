class Solution {
public:
     bool checkdfs(int node,int vis[],int pathvis[],vector<vector<int>>& adj,int check[])
    {
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(checkdfs(it,vis,pathvis,adj,check)==true)
                {
                check[node]=0;
                return true;
                }
            }
            else if(pathvis[it])
            {
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        int vis[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
        }
        int pathvis[V];
        for(int i=0;i<V;i++)
        {
            pathvis[i]=0;
        }
        int check[V];
        for(int i=0;i<V;i++)
        {
            check[i]=0;
        }
        vector<int>safenode;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                checkdfs(i,vis,pathvis,adj,check);
                
            }
        }
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
            {
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};