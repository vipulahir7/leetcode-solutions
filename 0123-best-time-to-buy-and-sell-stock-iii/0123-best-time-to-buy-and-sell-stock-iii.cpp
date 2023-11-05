class Solution {
public:
    
    int f(vector<int> & prices,int idx,int n,bool able,int count,vector<vector<vector<int>>>& dp){
        
        if(idx==n || count==0){
            return 0;
        }
        
        if(dp[idx][able][count-1]!=-1){
            return dp[idx][able][count-1];
        }
        
        if(able){
            return dp[idx][able][count-1]=max(f(prices,idx+1,n,false,count,dp) - prices[idx],f(prices,idx+1,n,true,count,dp));
        }
        return dp[idx][able][count-1]=max(f(prices,idx+1,n,true,count-1,dp)+prices[idx],f(prices,idx+1,n,false,count,dp));
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        
        return f(prices,0,n,1,2,dp);
    }
};