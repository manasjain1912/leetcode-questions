class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
          int numBooks = books.size();
     
        vector<int> dp(numBooks + 1);
      
        dp[0] = 0;
      
        for (int i = 1; i <= numBooks; ++i) {
           
            int currentWidth = books[i - 1][0], currentHeight = books[i - 1][1];
          
            dp[i] = dp[i - 1] + currentHeight;
        
            for (int j = i - 1; j > 0; --j) {
               
                currentWidth += books[j - 1][0];
            
                if (currentWidth > shelfWidth) {
                    break;
                }
              
                currentHeight = max(currentHeight, books[j - 1][1]);
      
                dp[i] = min(dp[i], dp[j - 1] + currentHeight);
            }
        }
        return dp[numBooks];
    }
};