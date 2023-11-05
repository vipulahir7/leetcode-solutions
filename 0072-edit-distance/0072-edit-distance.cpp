class Solution {
public:


    // int f(string a,string b,int n,int m,vector<vector<int>> &dp){

    //     if(m<0){
    //         return n+1;
    //     }

    //     if(n<0){
    //         return m+1;
    //     }

    //     if(dp[n][m]!=-1){
    //         return dp[n][m];
    //     }

    //     if(a[n]==b[m]){
    //         return dp[n][m]=f(a,b,n-1,m-1,dp);
    //     }
    //     return dp[n][m]=1+min(min(f(a,b,n-1,m,dp) , f(a,b,n,m-1,dp)) , f(a,b,n-1,m-1,dp));

    // }

    int minDistance(string a, string b) {
        int n=a.length(),m=b.length();

        vector<int> cur(m+1),prev(m+1);

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){

                if(i==0){
                    cur[j]=j;
                }
                if(j==0){
                    cur[j]=i;
                }
                if( i && j){
                    if(a[i-1]==b[j-1]){
                        cur[j]=prev[j-1];
                    }
                    else{
                        cur[j]=1+min(min(prev[j],cur[j-1]),prev[j-1]);
                    }
                }
            }
            prev=cur;
        }
        return prev[m];
    }
};