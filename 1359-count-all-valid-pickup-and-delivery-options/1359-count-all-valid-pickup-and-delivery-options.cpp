class Solution {
private:
    const int M = 1e9 + 7;

public:
    int countOrders(int n) {
        long ans = 1;
        for (long i = 2; i <= n; i++) {
            ans = (ans * i * (2 * i - 1)) % M;
        }

        return ans;
    }
};