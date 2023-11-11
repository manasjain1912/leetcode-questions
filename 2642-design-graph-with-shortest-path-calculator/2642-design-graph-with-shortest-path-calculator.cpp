class Graph {
public:
    int n ;
    unordered_map<int,vector<pair<int,int>>> g;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;

        for(auto edge : edges)  g[edge[0]].push_back({edge[1], edge[2]});
        
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1], edge[2]});
        
    }
    int shortestPath(int node1, int node2)
    {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);

    dist[node1] = 0;
    pq.push({0, node1});

    while (!pq.empty()) {
        int curdist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (curdist > dist[node]) continue;

        if (node == node2) return curdist;

        for (auto it : g[node]) {
            if (dist[it.first] > curdist + it.second) {
                int newdist = curdist + it.second;
                dist[it.first] = newdist;
                pq.push({newdist, it.first});
            }
        }
    }

    return -1;
    }
};