#include<bits/stdc++.h>
class Solution {
public:
    int mod = 1000000007;
    long long memo[205][205][205];
    long long check(int idx, int g1, int g2, int n, vector<int>& nums){
        if(idx == n){
            return (g1 == g2 && g1 != 0);
        }

        if(memo[idx][g1][g2] != -1){
            return memo[idx][g1][g2]%mod;
        }

        long long ans = 0;
        ans += check(idx+1, g1, g2, n, nums);
        ans += check(idx+1, g1==0?nums[idx]:__gcd(nums[idx],g1), g2, n, nums);
        ans += check(idx+1, g1, g2==0?nums[idx]:__gcd(nums[idx], g2), n, nums);
        memo[idx][g1][g2] = ans%mod;
        return memo[idx][g1][g2];
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        int n = nums.size();
        return check(0, 0, 0, n, nums);
    }
};