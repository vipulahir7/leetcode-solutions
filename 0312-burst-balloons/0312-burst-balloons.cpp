class Solution {
public:
    int dp[305][305];
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int size=nums.size();
        
        for(int i=size-2;i>=1;i--){
            for(int j=i;j<=size-2;j++){
                int ans=0;
                for(int k=i;k<=j;k++){
                    int temp=nums[i-1]*nums[j+1]*nums[k] + dp[i][k-1] + dp[k+1][j];
                    ans=max(temp,ans);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][size-2];
    }
};