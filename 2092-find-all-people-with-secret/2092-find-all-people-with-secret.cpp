class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(auto m:meetings){
            adj[m[0]].push_back({m[1],m[2]});
            adj[m[1]].push_back({m[0],m[2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int>> q;
        dist[0]=0;
        dist[firstPerson]=0;
        q.push({0,0});
        q.push({firstPerson,0});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int currPerson  = front.first;
            int currTime = front.second;
            for(auto nbr:adj[currPerson]){
                if(currTime<=nbr.second && dist[nbr.first]>nbr.second){
                    dist[nbr.first] = nbr.second;
                    q.push({nbr.first,nbr.second});
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++) if(dist[i]!=INT_MAX) ans.push_back(i);
        return ans;
    }
};