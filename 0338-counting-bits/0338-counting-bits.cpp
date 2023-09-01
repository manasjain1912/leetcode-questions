class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> res(n + 1);
        
        for(int i = 1; i < n + 1; i++) 
        {
            if(i % 2 == 0) 
            {
                res[i] = res[i >> 1];                
            }
            else
            {
                res[i] = res[i >> 1] + 1;
            }
        }
        
        return res; 
    }
};