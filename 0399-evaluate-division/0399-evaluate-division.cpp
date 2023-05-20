class Solution {
public:
    pair<double,bool> dfs(vector<vector<pair<int, double>>> const& edges, int cur, int goal, double val, unordered_set<int> visited) {
        if (cur == goal) {
            return {val,true};
        }
        for (auto const& p : edges[cur]) {
            int i = p.first;
            double v = p.second;
            if (visited.count(i)) {
                continue;
            }
            visited.insert(i);
            auto ret = dfs(edges, i, goal, val * v, visited);
            if (ret.second) {
                return ret;
            }
        }
        return {-1.0, false};
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = 0;
        unordered_map<string, int> m;
        for (auto const& eq : equations) {
            if (!m.count(eq[0])) {
                m[eq[0]] = n++;
            }
            if (!m.count(eq[1])) {
                m[eq[1]] = n++;
            }
        }
        
        vector<vector<pair<int, double>>> edges(n);
        for (int i = 0; i < (int)equations.size(); ++i) {
            auto const& eq = equations[i];
            int a = m[eq[0]];
            int b = m[eq[1]];
            double v = values[i];
            edges[a].push_back({b, v});
            if (v != 0.0) {
                edges[b].push_back({a, 1.0/v});
            }
        }
        
        vector<double> ans;
        for (auto const& q : queries) {
            if (!m.count(q[0]) || !m.count(q[1])) {
                // invalid
                ans.push_back(-1.0);
                continue;
            } 
            int a = m[q[0]];
            int b = m[q[1]];
            unordered_set<int> visited;
            visited.insert(a);
            // find path
            auto ret = dfs(edges, a, b, 1.0, visited);
            ans.push_back(ret.first);
        }
        return ans;
    }
};