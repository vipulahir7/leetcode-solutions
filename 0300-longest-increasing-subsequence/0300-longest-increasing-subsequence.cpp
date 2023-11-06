class Solution {
public:
//     int f(vector<int> & nums,int lastidx,int idx,vector<vector<int>>& dp){
        
//         if(idx<0){
//             return 0;
//         }
//         if(dp[lastidx+1][idx]!=-1){
//             return dp[lastidx+1][idx];
//         }
        
//         if(lastidx==-1 || nums[idx]<nums[lastidx]){
//             return dp[lastidx+1][idx]=max(1+f(nums,idx,idx-1,dp),f(nums,lastidx,idx-1,dp));
//         }
//         return dp[lastidx+1][idx]=f(nums,lastidx,idx-1,dp);
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=1;
        
        for(int idx=1;idx<n;idx++){
            for(int lastidx=0;lastidx<idx;lastidx++){
                
                if(nums[idx]>nums[lastidx]){
                    dp[idx]=max(dp[idx],dp[lastidx]+1);
                    ans=max(ans,dp[idx]);
                }
            }
        }
        
        return ans;
    }
};