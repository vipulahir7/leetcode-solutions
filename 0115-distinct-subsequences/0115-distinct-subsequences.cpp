class Solution {
public:

    int f(string s,string t,int n,int m,vector<vector<int>> &dp){

        if(m<0){
            return 1;
        }
        if(n<0){
            return 0;
        }

        if(dp[n][m]!=-1){
            return dp[n][m];
        }

        if(s[n]==t[m]){
            return dp[n][m]=f(s,t,n-1,m-1,dp)+f(s,t,n-1,m,dp);
        }

        return dp[n][m]=f(s,t,n-1,m,dp);
    }

    int numDistinct(string s, string t) {

        int n=s.length(),m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(s,t,n-1,m-1,dp);
    }
};