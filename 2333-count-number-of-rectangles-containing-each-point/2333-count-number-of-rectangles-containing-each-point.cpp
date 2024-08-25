class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
        vector<int> ans;

        vector<vector<int>> arr(101);
        for(auto num: r){
            arr[num[1]].push_back(num[0]);
        }

        for(auto& h : arr){
            sort(h.begin(), h.end());
        }
        
        for(auto point : p){
            int a = 0;
            int x = point[0], y = point[1];
            for(int i=y; i<=100; i++){
                a += arr[i].size() - (lower_bound(arr[i].begin(), arr[i].end(), x) - arr[i].begin());
            }
            ans.push_back(a);
        }
        return ans;
    }
};