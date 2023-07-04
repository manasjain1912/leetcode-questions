class Solution {
public:
    int singleNumber(vector<int>& vec) {
        map<int, int> M;
        int n=vec.size();
        int ans;
        for(int i=0;i<n;i++)
        {
           M[vec[i]]++;
        }
       for (auto it : M) {
        if(it.second==1)
        {
            ans=it.first;
        }
    }
      return ans;  
    }
};