class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        vector<pair<int,int>>vp;
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            vp.push_back(make_pair(count,i));
        }
        sort(vp.begin(),vp.end());
        
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};