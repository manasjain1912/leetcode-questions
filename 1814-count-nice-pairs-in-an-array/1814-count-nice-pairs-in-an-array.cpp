class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (auto &num : nums) {
            cnt[diff(num)]++;
        }
        int ans = 0;
        for (auto &p : cnt) {
            ans += ((long long)p.second * (p.second-1) / 2) % ((int)1e9+7);
            ans %= (int)1e9+7;
        }
        return ans;
    }

private:
    long long diff(long long num) {
        long long rev = 0;
        long long org = num;
        while (num != 0) {
            rev *= 10;
            rev += num % 10;
            num /= 10;
        }
        return rev - org;
    }
};