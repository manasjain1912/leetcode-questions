class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<int> v;  
        map<int,int> mp;
        
        for(auto x:arr)  mp[x]++;  
        for(auto x:mp) v.push_back(x.second); 
        
        sort(v.begin(),v.end()); 
        int i=0;
         
        for(i=0;i<v.size();i++)
        {
            if(k>=v[i])
            {
              k-=v[i]; 
            } 
            else break; 
        }
        return v.size()-i;  
    }
};