class Solution {
public:
        
    int f(vector<int>& prices ,int i,int n,bool ableToBuy,vector<vector<int>> &dp){
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i][ableToBuy]!=-1){
            return dp[i][ableToBuy];
        }
        
        if(ableToBuy){
            return dp[i][ableToBuy]=max(-prices[i] + f(prices,i+1,n,false,dp) , f(prices,i+1,n,true,dp));
        }
        return dp[i][ableToBuy]=max(prices[i] + f(prices,i+1,n,true,dp) , f(prices,i+1,n,false,dp));
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return f(prices,0,n,true,dp);
    }
};