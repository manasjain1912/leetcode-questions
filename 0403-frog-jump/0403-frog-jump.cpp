class Solution {
public:
    bool canCross(vector<int>& stones) {
          int n = stones.size();
          if(stones[1] != 1) return false;
        
          int target = stones[n - 1];
          map<int, set<int>> possibleJumps;
          
          for(int stone : stones){
              set<int> st;
              if(stone == 0){
                  st.insert(1);
              }
              possibleJumps[stone] = st;
          }
        
        
          for(auto i : possibleJumps){
               int stone = i.first;
                     
                for(auto jump : possibleJumps[stone]){
                    
                     if(possibleJumps.find(stone + jump) != possibleJumps.end()){
                           int k = jump;
                           if(k-1 > 0) possibleJumps[stone + jump].insert(k-1);
                           possibleJumps[stone + jump].insert(k);
                           possibleJumps[stone + jump].insert(k+1);
                     }
                }
          }
        
          return (possibleJumps[target].size() > 0) ? true : false;
                 
    }
};