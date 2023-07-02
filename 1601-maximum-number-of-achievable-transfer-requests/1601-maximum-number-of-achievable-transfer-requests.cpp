class Solution {
public:
    int maximumRequests(int bld, vector<vector<int>>& req) 
    {
        int n=req.size(),ans=0,fre[bld];
        for(int i=0;i<(1<<n);i++)
        {
            memset(fre,0,sizeof(fre));
            for(int j=0;j<n;j++)
                if(i & (1<<j))
                    fre[req[j][0]]--,fre[req[j][1]]++;
            int flag=1;
            for(int j=0;j<bld;j++)
                if(fre[j]) flag=0;
            if(flag) ans=max(ans,__builtin_popcount(i));
        }
        return ans;
    }
};