class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        return v1[0]<v2[0];
    }
    int solve(vector<vector<int>> &v,int time)
    {
        int low=0,high=v.size()-1;
        int ans=high+1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[mid][0]<=time)
            {
                ans=mid;
                low=mid+1;
            }
            else if(v[mid][0]>time)
            {
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<vector<int>> v;
        int n=flowers.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            v.push_back({flowers[i][0],1});
            v.push_back({flowers[i][1]+1,-1});
        }
       
        sort(v.begin(),v.end(),cmp);

        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i][1];
            mp[v[i][0]]=sum;
        }

        for(int i=0;i<people.size();i++)
        {
            int res=solve(v,people[i]);
            int val;
            if(res==v.size())
            {
                val=mp[v[v.size()-1][0]];
                ans.push_back(mp[val]);
                continue;
            }
            
            ans.push_back(mp[v[res][0]]);
        }

        return ans;
    }
};