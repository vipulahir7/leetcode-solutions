class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> count(1e5+1, 1e5+2);
        vector<vector<int>> ans(2);

        for(int i=0; i<matches.size(); i++){
            if(count[matches[i][0]] == 1e5+2) count[matches[i][0]] = 0;
            if(count[matches[i][1]] == 1e5+2) count[matches[i][1]] = 0;
            count[matches[i][1]]++;
        }
        for(int i=0; i<=1e5; i++){
            if(count[i]==0){
                ans[0].push_back(i);
            }
            else if(count[i] == 1){
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};