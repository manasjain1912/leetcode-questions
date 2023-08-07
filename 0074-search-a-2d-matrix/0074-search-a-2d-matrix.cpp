class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int x) {
      if(arr.size()==0)
      {
          return false;
      }
      int n=arr.size();
      int m=arr[0].size();
      int low=0;
      int high=n*m-1;
      while(low<=high)
      {
          int mid=(low + (high-low)/2);
          if(arr[mid/m][mid%m]==x)
          {
              return true;
          }
          if(arr[mid/m][mid%m]<x)//right
          {
              low=mid+1;
          }
          else //left
          {
              high=mid-1;
          }  
      }
        return false;
    }
};