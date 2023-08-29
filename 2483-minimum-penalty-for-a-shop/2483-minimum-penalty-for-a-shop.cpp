class Solution {
public:
    int bestClosingTime(string c) {
        int n=c.size();
        int count=0;
        int ans=0;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(c[i]=='Y')
            count++;
            else
            count--;
            if(count>ans)
            {
                ans=count;
                idx=i;
            }
        }
        return idx+1;
    }
};