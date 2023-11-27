class Solution {
public:

    long long check(vector<vector<long long>>&dp,int i,int n,int N,vector<int>* arr){
        if(i<0 || i>9)return 0;
        if(n==1)return 1;
        if(dp[i][n]!=-1)return dp[i][n];
        long long ans=0;
        for(int j:arr[i]){
            ans=(ans+check(dp,j,n-1,N,arr))%N;
        }
        return dp[i][n]=ans;
        return ans;
    }

    int knightDialer(int n) {
        vector<vector<long long>>dp(10,vector<long long>(n+1,-1));
        int N=1000000007;
        vector<int>graph[10]={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        long long ans=0;
        for(int i=0;i<10;i++){
            ans=(ans+check(dp,i,n,N,graph))%N;
        }
        return ans%N;
    }
};