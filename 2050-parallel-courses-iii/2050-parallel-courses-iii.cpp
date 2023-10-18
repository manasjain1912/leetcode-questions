class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& p, vector<int>& a) {
        vector<int> edge[n + 1];
        vector<int> deg(n + 1);
        for(auto i : p){
            edge[i[0]].push_back(i[1]);
            deg[i[1]]++;
        }
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(deg[i] == 0) q.push(i);
        }
        vector<int> dp(n + 1);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            dp[node] += a[node - 1];
            for(auto j : edge[node]) {
                if(!--deg[j]){
                    q.push(j);
                }
                dp[j] = max(dp[j], dp[node]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};