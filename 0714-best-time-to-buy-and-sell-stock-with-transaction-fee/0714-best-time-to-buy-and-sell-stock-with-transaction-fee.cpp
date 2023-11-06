class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int curBuy,curNotBuy,aheadBuy=0,aheadNotBuy=0;
        int n=prices.size();
        
        for(int i=n-1;i>=0;i--){
            curBuy=max(aheadNotBuy-prices[i], aheadBuy);   
            curNotBuy=max(aheadBuy+prices[i]-fee,aheadNotBuy);

            aheadBuy=curBuy;
            aheadNotBuy=curNotBuy;
        }
        return curBuy;
    }
};