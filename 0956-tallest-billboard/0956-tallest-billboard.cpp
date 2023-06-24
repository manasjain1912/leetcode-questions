class Solution {

public: 

    map<pair<int,int>,int> dp;

    int rec(vector<int> &rods, int diff, int idx){

      if(idx==rods.size()){

        if(diff==0) return 0;

        return -1e5;

      }

      if(dp.count({idx, diff})) return dp[{idx,diff}];

      int op1 = rods[idx]+rec(rods, diff+rods[idx], idx+1);

      int op2 = rec(rods,diff-rods[idx], idx+1);

      int op3 = rec(rods, diff, idx+1);

      return dp[{idx,diff}] = max({op1, op2,op3});

    }

    int tallestBillboard(vector<int>& rods) {

        return rec(rods, 0, 0);

    }

};