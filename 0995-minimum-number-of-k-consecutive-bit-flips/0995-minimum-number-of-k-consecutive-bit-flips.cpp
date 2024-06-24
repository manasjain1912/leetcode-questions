class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
      vector<int> flip(n, 0);
	int f = 0;
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		if ((f & 1) == nums[i]) {
			++tot;
			++f;

			if (i + k - 1 >= n) return -1;
			flip[i + k - 1] = 1;
		}
		f -= flip[i];
	}
	return tot;  
    }
};