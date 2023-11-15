class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mx=0;
        int x=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=x){
                mx=max(mx,x);
                x++;
            }
        }
        return mx;

    }
};