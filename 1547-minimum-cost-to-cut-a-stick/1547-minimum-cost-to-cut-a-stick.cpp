class Solution {
public:
    int dp[102][102];

    // int f(vector<int>&cuts,int i,int j,int n){
    //     if(i>j) return 0;
        
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
        
    //     int ans=INT_MAX;
    //     for(int k=i;k<=j;k++){
    //         int temp=f(cuts,i,k-1,n)+f(cuts,k+1,j,n);
    //         int left,right;
            
    //         if(i==0) left=0;
    //         else left=cuts[i-1];
            
    //         if(j==cuts.size()-1) right=n;
    //         else right=cuts[j+1];
    
    //         temp+=(right-left);
            
    //         ans=min(ans,temp);
    //     }
    //     return dp[i][j]=ans;
    // }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int size=cuts.size();

        for(int i=size-2;i>=1;i--){
            for(int j=i;j<=size-2;j++){
                int ans=INT_MAX;
                for(int k=i;k<=j;k++){
                    int temp=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    ans=min(temp,ans);
                }
                dp[i][j]=ans;
            }
        }
        // return f(cuts,0,size-1,n);
        return dp[1][size-2];
    }
};