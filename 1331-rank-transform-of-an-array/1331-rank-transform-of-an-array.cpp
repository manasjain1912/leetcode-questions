class Solution {

public:

    vector<int> arrayRankTransform(vector<int>& arr) {

        set<int>s(arr.begin(),arr.end()); 

        unordered_map<int,int>m; 

        vector<int>answ;

        

        for(auto val:s)

        {
            m[val]=m.size()+1;

        }

        for(auto val:arr)

        {

            answ.push_back(m[val]);

        }

        return answ;

        

    }

};
    