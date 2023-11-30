class Solution {
public:
    int minimumOneBitOperations(int n) {
        pair<int, int> p(0,1);
        for(long long i = 2; n; i *= 2, n /= 2)
        {
            if(n % 2) swap(p.first, p.second);
            p.second += i;
        }
        return p.first;
    }
};