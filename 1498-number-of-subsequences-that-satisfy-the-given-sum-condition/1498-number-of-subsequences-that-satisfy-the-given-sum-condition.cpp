class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        long long ans = 0;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                ans = (ans + power(2, right - left, MOD)) % MOD;
                left++;
            }
        }
        return ans;
    }
    
    int power(int base, int exp, int mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * (long long)base) % mod;
            }
            base = ((long long)base * base) % mod;
            exp /= 2;
        }
        return (int)res;
    }

};
