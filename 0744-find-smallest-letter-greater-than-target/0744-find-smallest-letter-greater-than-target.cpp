class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
       int n=arr.size();
        int start=0;
        int end=n-1;
        char ans='#';
        while(start<=end)
        {
            int mid= start + (end-start)/2;
           if(target<arr[mid])
            {
                
                end=mid-1;
               ans=arr[mid];
            }
            else
            {
                start=mid+1;
            }
        }
           if(ans=='#')
            ans = arr[0];
        return ans;
    }
};
 
           