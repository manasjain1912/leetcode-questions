class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        bitset<64> b=x;
        bitset<64> num=n;
        int f=log2(x)+10;
        int j=0;
        for(int i=0;i<64;i++){
            if(b[i]==0){
                b[i]=num[j];
                j++;
            }
            if(j==f){
                break;
            }
        }
        return b.to_ullong();
    }
};