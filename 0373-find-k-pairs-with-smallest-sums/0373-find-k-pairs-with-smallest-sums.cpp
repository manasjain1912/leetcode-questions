class Solution {

public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 

    {

      priority_queue<pair<int,pair<int,int>>>maxi ;

      

      for(int i=0;i<nums1.size();i++)

      {

        for(int j=0;j<nums2.size();j++)

        {

        

         if(maxi.size()<k)

         {

          maxi.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}}) ;

         }

         else if(maxi.size()==k && (nums1[i]+nums2[j])<maxi.top().first)

         {

             maxi.pop();

             maxi.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}}) ;

         }

         else if(maxi.size()==k && (nums1[i]+nums2[j])>maxi.top().first)

         {

           break ;

         }

      }  

    }

    vector<vector<int>>ans ;

    while(maxi.size()!=0)

    {

      ans.push_back({maxi.top().second.first,maxi.top().second.second}) ;

      maxi.pop() ;

    }

    reverse(ans.begin(),ans.end()) ;

    return ans ;

    }

};