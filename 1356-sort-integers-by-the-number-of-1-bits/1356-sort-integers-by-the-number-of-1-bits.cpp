class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        
        priority_queue<pair<int,int>> pq;
        long int count;
        
        for(int i=0;i<n;i++)
        {
            count=__builtin_popcount(arr[i]);
            pq.push({count,arr[i]});
            
        }
        
        int i=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            arr[i]=it.second;
            pq.pop();
            i++;
        }
        reverse(arr.begin(),arr.end());
        return arr;
        
    }
};
