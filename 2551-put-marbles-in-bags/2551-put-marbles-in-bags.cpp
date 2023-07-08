class Solution {
public:
long long int putMarbles(vector<int>& w, int k) 
{
     vector<long long int>v1;
     vector<long long int>v2;

          if(k == 1)
          {
              return 0;
          }
          if(k==2 && w.size()==2 && w[0]==w[1])
          {
              return 0;
          }
          if(k == w.size())
          {
              return 0;
          }
          k--;
          long long int temp = 0;
          long long int temp1 = 0;

          for(long long int i = 0;i<w.size()-1;i++)
          {
              v1.push_back(w[i]+w[i+1]);
          }
       
          for(long long int i = 0;i<w.size()-1;i++)
          {
              v2.push_back(w[i]+w[i+1]);
          }

         sort(v1.begin(),v1.end());
         sort(v2.begin() , v2.end());
    reverse(v1.begin(),v1.end());
for(long long int i =0;i<k;i++)
            {
                temp1+=v1[i];
                 temp+=v2[i];
            }
       long long ans=temp1 - temp;
        return ans;



    }
};