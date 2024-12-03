class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long sum = 0;

        vector<vector<int>> check(2005);
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            sum += num;
            check[num+1000].push_back(i);
        }

        int ans = -2000;

        for(int i=0; i<nums.size(); i++){
            int rs = sum;
            
                rs -= nums[i];
            if(rs % 2 != 0){
                continue;
            }

            
            rs/=2;
            if(rs <= 1000 && rs >=-1000 && check[rs+1000].size()){
                if(check[rs+1000].size() == 1 && check[rs+1000][0] == i){
                    continue;
                }
                ans = max(ans, nums[i]);
            }

        }
        return ans;
    }
}; 