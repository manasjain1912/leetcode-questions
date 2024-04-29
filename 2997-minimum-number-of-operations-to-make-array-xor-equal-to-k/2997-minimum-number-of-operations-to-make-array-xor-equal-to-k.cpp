class Solution{
public:
    int minOperations(vector<int>& arr, int k){
        int x=0, res=0;
        
        for(int& a:arr)
            x ^= a;
        
        while(x || k){
        
            if((x&1) != (k&1))
                res++;
            x >>= 1;
            k >>= 1;
        }

        return res;
    }
};