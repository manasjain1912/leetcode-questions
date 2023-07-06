class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int lefts[n],rights[n];
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())lefts[i]=0;
            else lefts[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.size()==0)rights[i]=n-1;
            else rights[i]=st.top()-1;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,heights[i]*(rights[i]-lefts[i]+1));
        }
        return ans;
    }
};
      
        

   