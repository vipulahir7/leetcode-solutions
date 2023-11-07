class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size(),maxi=1,len=1;
    vector<int> dp(n,1),count(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[j]+1>=dp[i]){
                if(dp[i]==(dp[j]+1)){
                    count[i]+=count[j];
                }
                else{
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
            }
        }
        if(dp[i]>len){
            len=dp[i];
            maxi=count[i];
        }
        else if(dp[i]==len){
            maxi+=count[i];
        }
    } 
    return maxi;   
    }
};