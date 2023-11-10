class Solution {
public:
    int dp[100][100];
    
    int f(vector<int>&cuts,int i,int j,int n){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int temp=f(cuts,i,k-1,n)+f(cuts,k+1,j,n);
            int left,right;
            
            if(i==0) left=0;
            else left=cuts[i-1];
            
            if(j==cuts.size()-1) right=n;
            else right=cuts[j+1];
    
            temp+=(right-left);
            
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int size=cuts.size();
        memset(dp,-1,sizeof(dp));
        
        return f(cuts,0,size-1,n);
        
    }
};