class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        for(int i=0;i<profit.size();i++){
            jobs.push_back({difficulty[i],profit[i]});
        }
         sort(worker.begin(), worker.end());
        sort(jobs.begin(),jobs.end());
       
     int maxProfit = 0;
        int ans = 0;
        int j = 0;
        
        for (int i = 0; i < worker.size(); i++) {
            while (j < jobs.size() && jobs[j].first <= worker[i]) {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }
            ans += maxProfit;
        }
        return ans;
    }
};