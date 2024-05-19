class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,int>> check;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2){
                check.push_back({i-1,i});
            }
        }
        n=queries.size();
        vector<bool> ans(n);
        for(int i=0;i<n;i++){
            int x=queries[i][0],y=queries[i][1];
            bool gotAns=true;
            for(auto p:check){
                if(p.first > y){
                    break;
                }

                if(p.first>=x && p.second <=y){
                    ans[i]=false;
                    gotAns=false;
                    break;
                }
            }
            if(gotAns){
                ans[i]=true;
            }

        }
        return ans;
    }
};