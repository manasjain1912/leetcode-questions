class Solution {
    private:
bool check(int start,int color[],vector<vector<int>>& adj,int V)
{
    color[start]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    return true;
}
    public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
         int color[V];
	    for(int i=0;i<V;i++)
	    {
	        color[i]=-1;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(check(i,color,adj,V)==false)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
    }
};