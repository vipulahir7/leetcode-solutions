class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);

        int ans = 1;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int temp=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    temp = max(temp, dp[j]);
                }
            }
            dp[i]=temp+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};