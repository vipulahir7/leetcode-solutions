class Solution {
public:
    int dp[101][10001];

    int solve(int egg,int end){

        if(end==0 || end==1 || egg==1){
            return dp[egg][end]=end;
        }
        if(dp[egg][end]!=-1){
            return dp[egg][end];
        }
        int ans=1e9;
        int l=1,r=end;

        while(l<=r){
            int k=l+(r-l)/2;
            int left=solve(egg-1,k-1);
            int right=solve(egg,end-k);
            int temp=1+max(left,right);
            if(left<right){
                l=k+1;
            }
            else{
                r=k-1;
            }
            ans=min(ans,temp);
        }
        return dp[egg][end]=ans;
    }

    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};