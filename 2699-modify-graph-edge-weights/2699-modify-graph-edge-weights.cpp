class Solution
{
public:
    int djkstra(int src, int dest, vector<pair<int, int>> adj[], int n)
    {
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> vis(n, 0);
        while (!pq.empty())
        {
            auto i = pq.top();
            pq.pop();
            if (vis[i.second])
                continue;
            vis[i.second] = 1;
            int d = i.first, node = i.second;
            for (auto it : adj[node])
            {
                if (it.second + d < dist[it.first])
                {
                    dist[it.first] = it.second + d;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        return dist[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        vector<vector<int>> ans;
        vector<pair<int, int>> adj[n];
        for (auto it : edges)
        {
            if (it[2] != -1)
            {
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
            }
        }
        int x = djkstra(source, destination, adj, n);
        cout << x;
        if (x < target)
        {
            return ans;
        }
        int change = 1e9;
        for (auto it : edges)
        {
            if (it[2] == -1)
            {
                adj[it[0]].push_back({it[1], 1});
                adj[it[1]].push_back({it[0], 1});
                int c = 1;

                int x = djkstra(source, destination, adj, n);
                if (x <= target)
                {
                    change = target - x;
                    c += x - 1;
                    ans.push_back({it[0], it[1], change + 1});
                }
                else
                {
                    ans.push_back({it[0], it[1], c});
                }
            }
            else
            {
                ans.push_back({it[0], it[1], it[2]});
            }
        }
        if (change == 1e9)
        {
            if (x == target)
                return edges;
            return {};
        }

        return ans;
    }
};