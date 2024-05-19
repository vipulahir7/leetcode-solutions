#include<cmath>

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> arr(log10(nums[0])+1,vector<int> (10,0));
        long long ans=0;
        for(int i=0;i<n;i++){
            int num=nums[i];

            for(int pos=0;num;pos++){
                int numAtPos=num%10;
                num/=10;
                if(i){
                    ans+=(i-arr[pos][numAtPos]);
                }
                arr[pos][numAtPos]++;

            }
        }
        return ans;
    }
};