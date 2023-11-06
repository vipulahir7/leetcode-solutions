class Solution {
public:

    // int f(vector<int>& prices,int idx,int size,bool able,vector<vector<int>> &dp){

    //     if(idx>=size){
    //         return 0;
    //     }

    //     if(dp[idx][able]!=-1){
    //         return dp[idx][able];
    //     }
    //     if(able){
    //         return  dp[idx][able]=max(f(prices,idx+1,size,false,dp)-prices[idx],f(prices,idx+1,size,true,dp));
    //     }
    //     return  dp[idx][able]=max(f(prices,idx+2,size,true,dp)+prices[idx],f(prices,idx+1,size,false,dp));

    // }

    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        vector<int> cur(2),ahead(2,0),ahead2(2,0);

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    cur[j]=max(ahead[0]-prices[i],ahead[1]);
                }
                else{
                    cur[j]=max(ahead2[1]+prices[i],ahead[0]);
                }
            }
            ahead2=ahead;
            ahead=cur;
        }
        

        return ahead[1];
    }
};