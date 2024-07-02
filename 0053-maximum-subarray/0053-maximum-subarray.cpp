class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = *max_element(nums.begin(), nums.end());
        for (auto num : nums) {
            sum+=num, maxSum = max(maxSum, sum); 
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};