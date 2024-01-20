class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long sum = 0;
        stack<pair<int, long>> sums;
        for(int i = n - 1; i >= 0; i--) {
            while(!sums.empty() && arr[i] <= arr[sums.top().first]) 
                sums.pop();
            if(sums.empty()) 
                sums.push({i, (arr[i] * (n - i))%mod});
            else 
                sums.push({i, (sums.top().second + arr[i] * (sums.top().first - i))%mod});
            sum = (sum + sums.top().second)%mod;
        }
        return sum%mod;  
    }
};