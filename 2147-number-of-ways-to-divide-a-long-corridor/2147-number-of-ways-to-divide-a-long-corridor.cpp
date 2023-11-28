class Solution {
public:
    int numberOfWays(string corridor) {
        int numChairs = 0, chCount = 0, plCount = 0;
        long long res = 1;
        const long long mod = 1e9 + 7;

        for (auto c : corridor)
        {
            if (chCount == 2)
            {
                if (c == 'S')
                {
                    res = (res * (plCount + 1)) % mod;
                    plCount = 0;
                    chCount = 1;
                    ++numChairs;
                }
                else
                    ++plCount;
            }
            else if (c == 'S')
                ++chCount, ++numChairs;
        }

        if (numChairs & 1 || numChairs < 1)
            return 0;

        return res;
    }
};