class Solution {
public:
static  bool cmp(pair<char,int>& a, pair<char, int>& b)
{
    return a.second > b.second;
}
string frequencySort(string s)
{
    string ans="";
    map<char,int>mp;
    vector<pair<char,int>>p;
    for(auto i:s)
    {
        mp[i]++;
    }
    for(auto i:mp)
    {
        p.push_back(make_pair(i.first,i.second));
    }
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<p.size();i++)
    {
         while(p[i].second!=0)
         {
             ans+=p[i].first;
             p[i].second--;
         }
    }
    return ans;
}
};