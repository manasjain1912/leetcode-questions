class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        if(n==1)
        {
            return pref;
        }
        vector<int>temp(n);
        temp[0]=pref[0];
        for(int i=0;i<n-1;i++)
        {
            temp[i+1]=pref[i]^pref[i+1];
        }
        return temp;
    }
};