class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();

        int memo[n];
        for(int idx=0;idx<n;idx++){

            int ans=INT_MIN;
            int maxTill=arr[idx];
            for(int i=1;i<=k && idx-i+1>=0;i++){
                maxTill=max(maxTill,arr[idx-i+1]);
                int temp=maxTill*i;
                if(idx-i>=0){
                    temp+=memo[idx-i];
                }
                ans=max(ans,temp);
            }
            memo[idx]=ans;
        }

        return memo[n-1];
    }
};