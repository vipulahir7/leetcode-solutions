class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1000001,current = 0;
        for(auto num : nums) {
            current = max(num, num + current);
            ans = max(ans, current);
        }
        return ans;
    }
};