class compare{
    public:
    bool operator()(vector<int>&a,vector<int>& b){
        return a[1]<b[1];
    }
}mycmp;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
       int len=pairs.size();
       sort(pairs.begin(),pairs.end(),mycmp);
       int end=pairs[0][1],res=1;
       for(int i=1;i<len;i++)
       {
            if(end<pairs[i][0])
            {
                res++;
                end=pairs[i][1];
            }
       }
       return res;
    }
};