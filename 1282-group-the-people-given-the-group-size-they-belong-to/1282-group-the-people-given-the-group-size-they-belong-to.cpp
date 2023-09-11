class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		   int n=groupSizes.size()-1;
		   unordered_map<int, vector<int>> mp;
		   vector<vector<int>> ans;
		 for(int i=0;i<=n;i++){
			 mp[groupSizes[i]].push_back(i);
		 }
		 for(auto it: mp){
			 int t=it.first,c=0;
			 vector<int> arr=it.second;
			 vector<int> v;
			 for(int i=0;i<arr.size();i++){
				 v.push_back(arr[i]);
				 c++;
				 if(c==t){
					 ans.push_back(v);
					 c=0;
					 v.clear();
				 }
			 }
		 }
		return ans;
	}
};