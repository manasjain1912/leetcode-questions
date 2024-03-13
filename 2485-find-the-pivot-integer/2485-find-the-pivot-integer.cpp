class Solution {
public:
    int pivotInteger(int n) {
        int ans=-1;
        int temp=(n*n+n)/2;
        ans=sqrt((n*n+n)/2);
        if(pow(ans,2)==temp)
        return ans;
        else
            return -1;
    }
};