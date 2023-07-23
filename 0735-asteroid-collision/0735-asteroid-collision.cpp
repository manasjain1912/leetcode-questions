class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto a:asteroids)
        {
            while(!st.empty() && a<0 && st.top()>0)
            {
                int sum=a+st.top();
                if(sum<0)
                {
                    st.pop();
                }
                else if(sum>0)
                {
                    a=0;
                }
                else
                {
                    st.pop();
                    a=0;
                }
            }
            if(a!=0)
            {
                st.push(a);
            }
        }
        int n=st.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};