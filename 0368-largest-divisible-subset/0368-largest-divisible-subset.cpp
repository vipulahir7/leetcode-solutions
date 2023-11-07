class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxIdx=0;

        vector<int> idx(n),len(n,1);
        idx[0]=0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && (len[j] > len[i]-1)){
                    len[i]=(len[j]+1);
                    idx[i]=j;
                }
            }
            if(len[i]>len[maxIdx]){
                maxIdx=i;
            }
        }
        cout<<endl;

        vector<int> ans;
        while(len[maxIdx]!=1){
            ans.push_back(nums[maxIdx]);
            maxIdx=idx[maxIdx];
        }
        ans.push_back(nums[maxIdx]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};