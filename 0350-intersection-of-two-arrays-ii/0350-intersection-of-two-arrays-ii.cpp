class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c1 (1001, 0), c2(1001, 0);
        for(auto num : nums1) c1[num]++;
        for(auto num : nums2) c2[num]++;
        vector<int> ans;
        for(int i=0; i<=1000; i++){
            if(c1[i] && c2[i]) {
                int num = min(c1[i], c2[i]);
                while(num--) ans.push_back(i);
            }
        }
        return ans;
    }
};