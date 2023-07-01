class Solution {
public:
    int ans=INT_MAX;
    void solve(vector<int>& cookies, int n,int k,vector<int> &stu)
    {
        if(n==0)
        {
            int mx=*max_element(stu.begin(),stu.end());
            ans=min(ans,mx);
            return;
        }
        for(int j=0;j<k;j++)
        {
            stu[j]+=cookies[n-1];
            solve(cookies,n-1,k,stu);
            stu[j]-=cookies[n-1];
        }
                                
                    
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int> stu(k);
        solve(cookies,n,k,stu);
        return ans;
    }   
};