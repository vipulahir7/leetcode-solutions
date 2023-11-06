class Solution {
public:
    int f(vector<int> & nums,int lastidx,int idx,vector<vector<int>>& dp){
        
        if(idx<0){
            return 0;
        }
        if(dp[lastidx+1][idx]!=-1){
            return dp[lastidx+1][idx];
        }
        
        if(lastidx==-1 || nums[idx]<nums[lastidx]){
            return dp[lastidx+1][idx]=max(1+f(nums,idx,idx-1,dp),f(nums,lastidx,idx-1,dp));
        }
        return dp[lastidx+1][idx]=f(nums,lastidx,idx-1,dp);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        
        return f(nums,-1,n-1,dp);
    }
};