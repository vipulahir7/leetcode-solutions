class Solution {
public:
    int maxProfit(int times, vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> prev(2,vector<int>(times+1,0)),cur(2,vector<int>(times+1));
        for(int i=n;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=times;k++){
                    if(i==n||k==0){
                        cur[j][k]=0;
                    }
                    else{

                        if(j){
                            cur[j][k]=max(prev[0][k]-prices[i],prev[1][k]);
                        }
                        else{
                            cur[j][k]=max(prev[1][k-1]+prices[i],prev[0][k]);
                        }
                    }
                }
            }
            prev=cur;
        }

        return prev[1][times];
        
    }
};


        
        