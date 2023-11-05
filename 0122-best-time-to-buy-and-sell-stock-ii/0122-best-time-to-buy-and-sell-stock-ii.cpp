class Solution {
public:
        
//     int f(vector<int>& prices ,int i,int n,bool ableToBuy,vector<vector<int>> &dp){
        
//         if(i>=n){
//             return 0;
//         }
        
//         if(dp[i][ableToBuy]!=-1){
//             return dp[i][ableToBuy];
//         }
        
//         if(ableToBuy){
//             return dp[i][ableToBuy]=max(-prices[i] + f(prices,i+1,n,false,dp) , f(prices,i+1,n,true,dp));
//         }
//         return dp[i][ableToBuy]=max(prices[i] + f(prices,i+1,n,true,dp) , f(prices,i+1,n,false,dp));
        
//     }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<int> prev(2,0),cur(2);
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    cur[j]=max(prev[0]-prices[i],prev[1]);
                }   
                else{
                    cur[j]=max(prices[i]+prev[1],prev[0]);
                }
            }
            prev=cur;
        }
        
        return prev[1];
    }
};