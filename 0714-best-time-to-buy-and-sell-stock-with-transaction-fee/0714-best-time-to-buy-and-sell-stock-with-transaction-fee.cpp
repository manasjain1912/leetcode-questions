class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0], sell = 0;
        for(auto x: prices) {
            buy = max(buy, sell-x);
            sell = max(sell, buy+x-fee);
        }
        return sell;
    }
};