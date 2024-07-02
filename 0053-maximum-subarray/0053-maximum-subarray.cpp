class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1000001,current = 0;
        for(auto num : nums) {
            current += num;
            ans = max(ans, current);
            if(current < 0) current  = 0;
        }
        return ans;
    }
};