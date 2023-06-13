class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
      vector<int>ans;
        int n=arr.size();
    deque<int>q;
    int i=0,j=0;
    while(j<n)
    {
        while(!q.empty() && arr[j]>q.back())
        {
            q.pop_back();
        }
        q.push_back(arr[j]);
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            ans.push_back(q.front());
            if(arr[i]==q.front())
            {
                q.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
    }
};