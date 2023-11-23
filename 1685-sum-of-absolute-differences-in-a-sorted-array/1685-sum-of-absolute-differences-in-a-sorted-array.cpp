class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0),sum(n,0);
        sum[0]=nums[0];
        
        for(int i=1;i<n;i++){
            sum[i]=nums[i]+sum[i-1];
        }
        
        for(int i=0;i<n;i++){
            int left=0,right=0;
            
            if(i){
                left=i*nums[i]-sum[i-1];
            }
            if(i<n-1){
                right=sum[n-1]-sum[i]-(n-i-1)*nums[i];
            }   
            ans[i]=left+right;
        }
        return ans;   
    }
};