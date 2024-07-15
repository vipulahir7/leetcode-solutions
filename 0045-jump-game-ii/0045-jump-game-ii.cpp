class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, next = 0,nextMaxi = 0;
        if(nums.size()==1) return 0;
        for(int i=0; i<nums.size()-1; i++){
            nextMaxi = max(nextMaxi, nums[i]+i);
            if(i == next){
                ans++;
                next = nextMaxi;
            }
        }
        return ans;
    }
};