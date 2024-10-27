#include<bits/stdc++.h>
class Solution {
public:

    long long ret(vector<int> n, int idx){
        long long g = idx==0?n[1]:n[0], l = idx==0?n[1]:n[0];
        for(int i=1; i<n.size(); i++){
            if(idx == i) continue;
            g = __gcd(g, (long long)n[i]);
            l = (l*n[i])/__gcd(l, (long long)n[i]);
        }
        return g*l;
    }

    long long maxScore(vector<int>& nums) {
        if(nums.size()==1) return nums[0]*nums[0];
        long long ans = ret(nums, -1);
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, ret(nums, i));
        }
        return ans;
    }
};