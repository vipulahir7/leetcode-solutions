class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> cur(2),ahead(2,0);
        int n=prices.size();
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    cur[j]=max(ahead[0]-prices[i], ahead[j]);   
                }
                else{
                    cur[j]=max(ahead[1]+prices[i]-fee,ahead[j]);
                }
            }
            ahead=cur;
        }
        return ahead[1];
    }
};