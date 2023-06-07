class Solution {
public:
    int minFlips(int a, int b, int c) {
      int ans =0;
        for(int i = 0; i<32; ++i){
            long long x = 1<<i;
            if((a&x) && (b&x) && !(c&x)) ans +=2;
            else if(((a&x) || (b&x)) && !(c&x)) ++ans;
            else if(!(a&x) && !(b&x) && (c&x)) ++ans;
        }
        return ans;  
    }
};