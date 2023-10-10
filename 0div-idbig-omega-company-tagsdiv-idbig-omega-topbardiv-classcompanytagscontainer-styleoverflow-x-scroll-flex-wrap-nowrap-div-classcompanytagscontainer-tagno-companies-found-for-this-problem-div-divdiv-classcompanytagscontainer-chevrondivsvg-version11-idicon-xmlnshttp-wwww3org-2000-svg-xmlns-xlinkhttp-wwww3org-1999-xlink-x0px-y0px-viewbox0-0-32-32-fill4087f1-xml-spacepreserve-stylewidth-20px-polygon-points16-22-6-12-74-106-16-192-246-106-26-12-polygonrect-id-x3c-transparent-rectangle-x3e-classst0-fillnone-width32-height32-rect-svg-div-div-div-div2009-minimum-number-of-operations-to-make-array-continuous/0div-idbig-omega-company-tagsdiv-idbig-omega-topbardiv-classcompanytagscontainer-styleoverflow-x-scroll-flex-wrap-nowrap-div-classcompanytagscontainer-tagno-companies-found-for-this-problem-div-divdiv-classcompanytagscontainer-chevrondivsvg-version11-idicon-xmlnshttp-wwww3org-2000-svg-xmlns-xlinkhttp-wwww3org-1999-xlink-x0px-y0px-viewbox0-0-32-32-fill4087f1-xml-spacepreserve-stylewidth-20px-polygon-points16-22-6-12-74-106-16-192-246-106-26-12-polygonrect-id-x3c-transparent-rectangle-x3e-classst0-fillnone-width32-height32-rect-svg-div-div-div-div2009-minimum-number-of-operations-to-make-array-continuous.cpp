class Solution {
public:
    int minOperations(vector<int>& v) {
        int k = v.size();
        map <int, int> mp;
        for(auto &it: v) mp[it]++;
        vector <int> nums, pre(mp.size());
        for(auto &it: mp) nums.push_back(it.first);
        
        int n = nums.size(), ans = 0;
        
        sort(nums.begin(), nums.end());
        
        pre[0] = mp[nums[0]];
        
        for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + mp[nums[i]];

        int mn = k;
        for(int i = 0; i < n; i++) {
            int mx = nums[i] + k - 1;
            int j = upper_bound(nums.begin(), nums.end(), mx) - nums.begin();
            int need = k - (j - i);
            
            int freqSum = 0;
            if(i == 0) freqSum += pre[j - 1];
            else freqSum += pre[j - 1] - pre[i - 1];
            freqSum -= j - i;
            need = min(need, freqSum);
            need += pre[n - 1] - pre[j - 1];
            if(i - 1 >= 0) need += pre[i - 1];
            
            mn = min(mn, need);
        }
        return mn;
    }
};