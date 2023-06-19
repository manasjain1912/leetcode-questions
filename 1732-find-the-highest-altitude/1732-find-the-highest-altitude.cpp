class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>prefix(n);
         prefix[0] = gain[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]= prefix[i - 1] + gain[i];
        }
        sort(prefix.begin(),prefix.end());
        if(prefix[n-1]<0 )
            return 0;
        return prefix[n-1];
    }
};