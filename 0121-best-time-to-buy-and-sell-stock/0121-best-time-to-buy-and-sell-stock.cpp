class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        int minTill=INT_MAX;
        int ans=0;

        for(int i=0;i<n;i++){
            minTill=min(minTill,prices[i]);
            ans=max(ans,prices[i]-minTill);
        }
        return ans;
    }
};