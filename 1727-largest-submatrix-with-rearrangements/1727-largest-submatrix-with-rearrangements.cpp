class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
       int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> heghts(n), order_heights(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    heghts[j] = 0;
                }
                else {
                    heghts[j]++;
                }
                order_heights[j] = heghts[j];
            }
            sort(order_heights.begin(), order_heights.end());

            for (int j = 0; j < n; j++) {
                ans = max(ans, order_heights[j] * (n - j));
            }
        }
        return ans;
 
    }
};