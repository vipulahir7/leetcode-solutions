class Solution {
public:

    // int f(string s,string t,int n,int m,vector<vector<int>> &dp){

    //     if(m<0){
    //         return 1;
    //     }
    //     if(n<0){
    //         return 0;
    //     }

    //     if(dp[n][m]!=-1){
    //         return dp[n][m];
    //     }

    //     if(s[n]==t[m]){
    //         return dp[n][m]=f(s,t,n-1,m-1,dp)+f(s,t,n-1,m,dp);
    //     }

    //     return dp[n][m]=f(s,t,n-1,m,dp);
    // }

    int numDistinct(string s, string t) {

        int n=s.length(),m=t.length();
        vector<double> prev(m+1,0),cur(m+1);
        prev[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0){
                    cur[j]=1;
                }

                if(i && j){
                    if(s[i-1]==t[j-1]){
                        cur[j]=prev[j-1]+prev[j];
                    }
                    else{
                        cur[j]=prev[j];
                    }
                }
            }
            prev=cur;
        }

        return (int)prev[m];
    }
};