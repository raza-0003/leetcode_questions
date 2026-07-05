class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<int,int> solve(int i,int j,
                        vector<string>& board,
                        vector<vector<pair<int,int>>>& dp){

        int n = board.size();

        if(i>=n || j>=n)
            return {-1,0};

        if(board[i][j]=='X')
            return {-1,0};

        if(i==n-1 && j==n-1)
            return {0,1};

        if(dp[i][j].first!=-2)
            return dp[i][j];

        auto down = solve(i+1,j,board,dp);
        auto right = solve(i,j+1,board,dp);
        auto diag = solve(i+1,j+1,board,dp);

        int best=max({down.first,right.first,diag.first});

        if(best==-1)
            return dp[i][j]={-1,0};

        long long ways=0;

        if(down.first==best)
            ways=(ways+down.second)%MOD;

        if(right.first==best)
            ways=(ways+right.second)%MOD;

        if(diag.first==best)
            ways=(ways+diag.second)%MOD;

        int val=0;

        if(board[i][j]>='1' && board[i][j]<='9')
            val=board[i][j]-'0';

        return dp[i][j]={best+val,(int)ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n=board.size();

        vector<vector<pair<int,int>>> dp(
            n,
            vector<pair<int,int>>(n,{-2,-2})
        );

        auto ans=solve(0,0,board,dp);

        if(ans.first==-1)
            return {0,0};

        return {ans.first,ans.second};
    }
};