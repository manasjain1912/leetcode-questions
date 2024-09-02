class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        int n=chalk.size();
        for(int i =0; i < n; ++i)
            sum += chalk[i];
        k = k%sum;
        for(int i =0; i < n; ++i)
        {
            if(k < chalk[i])
                return i;
            k -=chalk[i];
        }
        return 0;
    }
};