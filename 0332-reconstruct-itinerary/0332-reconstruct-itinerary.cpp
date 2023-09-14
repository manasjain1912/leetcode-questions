#define min_pq priority_queue<string,vector<string>,greater<string>>
class Solution {
public:
    void dfs(string src,unordered_map<string,min_pq> &mp,vector<string> &ans){
        auto &pq = mp[src];
        
        while(pq.size()){
            string dest = pq.top(); pq.pop();
            dfs(dest,mp,ans);
        }
        
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,min_pq> mp;
        for(auto &vec : tickets){
            auto &pq = mp[vec.front()];
            for(int i=1;i<vec.size();i++) pq.push(vec[i]);
        }
        vector<string> ans;
        dfs("JFK",mp,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};