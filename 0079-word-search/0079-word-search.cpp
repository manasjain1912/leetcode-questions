class Solution {
public:
    bool solve(int i,int j,int m,int n,int k,vector<vector<char>>& board,string word)
    {
        if(k==word.size())
        {
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[k])
        {
            return false;
        }
        char c=board[i][j];
        board[i][j]='#';
        bool op1=solve(i+1,j,m,n,k+1,board,word);
        
        bool op2=solve(i-1,j,m,n,k+1,board,word);
        
        bool op3=solve(i,j-1,m,n,k+1,board,word);
        
        bool op4=solve(i,j+1,m,n,k+1,board,word);
        
        board[i][j]=c;
        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(i,j,m,n,0,board,word))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};