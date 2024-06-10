int dp[505][505][27];

class Solution {
public:
    
    int solve(vector<int> & nums , int k, int i,int prevIdx){
        if(i<0) return 0;

        if(prevIdx == -1){
            return max(1 + solve(nums,k,i-1,i), solve(nums,k,i-1,prevIdx));
        }

        if(dp[i][prevIdx][k] != -1) return dp[i][prevIdx][k];
        
        if(k==0) {
            if(nums[prevIdx] == nums[i]){
                return dp[i][prevIdx][k]=(1 + solve(nums,k,i-1,i));
            }
            else{
                return dp[i][prevIdx][k]=solve(nums,k,i-1,prevIdx);
            }
        }
        else{
            if(nums[prevIdx] == nums[i]){
                return dp[i][prevIdx][k]=(1 + solve(nums,k,i-1,i));
            }
            else{
                return dp[i][prevIdx][k]=max(1 + solve(nums,k-1,i-1,i),solve(nums,k,i-1,prevIdx));
            }
        }
        
    }
    
    int maximumLength(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(nums,k,nums.size()-1,-1);
    }
};