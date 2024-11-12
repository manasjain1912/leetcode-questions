class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int>price;
        
        for(int i=0;i<queries.size();i++){
            price[queries[i]] = 0;
        }
        
        for(int i=0;i<items.size();i++){
            price[items[i][0]] = max(price[items[i][0]], items[i][1]);
        }
        
        int MAX = INT_MIN;
        for(auto& [key,value]: price){
            MAX = max(MAX, value);
            value = MAX;
        }
        
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(price[queries[i]]);
        }
        return ans;
    }
};