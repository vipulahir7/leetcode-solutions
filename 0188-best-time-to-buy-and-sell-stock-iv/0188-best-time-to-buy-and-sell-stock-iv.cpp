class Solution {
public:
    int maxProfit(int times, vector<int>& prices) {
        int n=prices.size();
        
        vector<int> prev(2*times+1,0),cur(2*times+1);
        
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<2*times;k++){
                    if(k&1){//sell
                        cur[k]=max(prices[i]+prev[k+1],prev[k]);
                    }
                    else{//buy
                        cur[k]=max(prev[k+1]-prices[i],prev[k]);
                    }
                }
            cur[2*times]=0;
            prev=cur;
        }

        return prev[0];
    }
};


        
        