class Solution {
public:
      int MAH(vector<int>arr)
    {
        int n = arr.size();
        vector<int> nsl;
        stack<pair<int,int>> s1;
        for(int i=0; i<n; i++){
            while(!s1.empty() && s1.top().first>=arr[i]){
                s1.pop();
            }
            
            if(s1.empty()){
                nsl.push_back(-1);
            }
            else{
                nsl.push_back(s1.top().second);
            }
            
            if(i<n-1 && arr[i]<arr[i+1]){
                s1.push({arr[i],i});
            }
        }
        
        
        // next smaller right
        vector<int> nsr;
        stack<pair<int,int>> s2;
        for(int i=n-1; i>=0; i--){
            while(!s2.empty() && s2.top().first>=arr[i]){
                s2.pop();
            }
            
            if(s2.empty()){
                nsr.push_back(n);
            }
            else{
                nsr.push_back(s2.top().second);
            }
            
            if(i>0 && arr[i]<arr[i-1]){
                s2.push({arr[i],i});
            }
        }
        
        reverse(nsr.begin(),nsr.end());
        
        int  maxi = 0;
        
        for(int i=0; i<n; i++){
            maxi = max(maxi,((nsr[i]-nsl[i]-1)*arr[i]));
        }
        
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v;
        for(int i=0;i<m;i++)
        {
            v.push_back(matrix[0][i]-'0');
        }
        int mx=MAH(v);
         for(int i=1;i<n;i++)
        {
             for(int j=0;j<m;j++)
             {
              if(matrix[i][j]=='0')
              {
                  v[j]=0;
              }
                 else
                 {
                     v[j]=v[j]+1;
                 }
             }
             mx=max(mx,MAH(v));
           
        }
        return mx;
    }
};