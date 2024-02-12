class Solution {
public:
    int memo[70][70][70];
    int n, m;
    int cherryPickup(vector<vector<int>>& A) {
        n = A.size(), m = A[0].size();
        for(int i = 0; i < 70; i++)
            for(int j = 0; j < 70; j++)
                for(int k = 0; k < 70; k++)
                    memo[i][j][k] = -1;
        return max(0,dp(A, 0, 0, m - 1));
    }
    int dp(vector<vector<int>>& A, int r, int c1, int c2){
        if(c1 < 0 || c1 == m || c2 < 0 || c2 == m)
            return -1e9;
        if(r == n)
            return 0;
        if(memo[r][c1][c2] != -1)
            return memo[r][c1][c2];
        int best = 0;
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++)
                best = max(best, dp(A, r + 1, c1 + i, c2 + j));
        return memo[r][c1][c2] = best + (c1 == c2 ? A[r][c1] : A[r][c1] + A[r][c2]);
    }
};