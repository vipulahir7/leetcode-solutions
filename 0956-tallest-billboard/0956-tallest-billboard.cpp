class Solution {
public:
    
    vector<vector<int>> dp;

    int f(int idx,int dif,vector<int>&rods){

        if(idx<0){
            if(dif==0){
                return 0;
            }
            return -1e9;
        }
        
        if(dp[idx][dif+5000]!=-1){
            return dp[idx][dif+5000];
        }
        
        return dp[idx][dif+5000]=max(f(idx-1,dif,rods), max(rods[idx]+f(idx-1,dif+rods[idx],rods),f(idx-1,dif-rods[idx],rods)));
    }

    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        dp.resize(n+1,vector<int>(20001,-1));
        // memset(dp,-1,sizeof(dp));
        int ans=f(n-1,0,rods);
        return ans;
    }
};