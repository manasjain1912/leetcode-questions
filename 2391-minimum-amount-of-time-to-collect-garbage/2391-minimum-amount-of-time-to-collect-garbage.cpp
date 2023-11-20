class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
              int n = garbage.size();
        vector<unordered_map<char, int>> house_count(n);
        unordered_map<char, int> total_count;
        for (int i = 0; i < n; i++) {
            for (auto& c : garbage[i]) {
                house_count[i][c]++;
                total_count[c]++;
            }
        }
        int time = 0;
        for (auto& type : "MPG") {
            for (int i = 0; i < n; i++) {
                time += house_count[i][type];
                total_count[type] -= house_count[i][type];
                if (total_count[type] == 0) break;
                if (i < (n - 1)) time += travel[i];
            }
        }
        return time;
    }
};