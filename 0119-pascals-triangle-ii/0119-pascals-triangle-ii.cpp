class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> res(rowIndex+1);
         int n = (rowIndex>>1)+1;
         int j = rowIndex;
         long long x =1, div =1;
         res[0]=1;
         res[j]=1;
        for(int k =1;k< n;k++){
            x *=j;
            x/=k;
            res[k]=x;
            j--;
            res[j]=x;
        }         
        return res;
    }
};