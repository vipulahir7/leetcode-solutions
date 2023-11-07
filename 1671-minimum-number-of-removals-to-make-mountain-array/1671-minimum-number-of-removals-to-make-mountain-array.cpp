class Solution {
public:
int longestBitonicSubsequence(vector<int>& nums, int n)
{

    vector<int> dp1(n,1);
        for(int idx=1;idx<n;idx++){
            for(int lastidx=0;lastidx<idx;lastidx++){
                
                if(nums[idx]>nums[lastidx]){
                    dp1[idx]=max(dp1[idx],dp1[lastidx]+1);
                }
            }
    }
    vector<int> dp2(n,1);
        for(int idx=n-2;idx>=0;idx--){
            for(int lastidx=n-1;lastidx>idx;lastidx--){
                
                if(nums[idx]>nums[lastidx]){
                    dp2[idx]=max(dp2[idx],dp2[lastidx]+1);
                }
            }
        }

	int ans=0;
	for(int i=0;i<n;i++){
        if(dp1[i]==1||dp2[i]==1) continue;
		ans=max(ans,dp1[i]+dp2[i]-1);
	}
	return ans;
}

    int minimumMountainRemovals(vector<int>& nums) {
        return nums.size()-longestBitonicSubsequence(nums,nums.size());
    }
};