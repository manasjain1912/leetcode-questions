class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>map;
        int n=routes.size();
        for(int i=0;i<n;i++){
            for(auto j:routes[i]){
                map[j].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        vector<int>vis(1000000,false);
        vector<int>route_vis(1000000,false);
        q.push({source,0});
        int ans=0;
        while(!q.empty())
        {
            int a=q.front().first;
            int b=q.front().second;
            vis[a]=true;
            q.pop();
            if(a==target)return b;
            for(auto i:map[a]){
                if(route_vis[i]==false)
                {
                    route_vis[i]=true;
                for(auto j:routes[i])
                {
                    if(!vis[j]) q.push({j,b+1});
                }
                }
            }
        }
        return -1;
    }
};