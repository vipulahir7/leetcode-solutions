class Solution {
public:

    bool validate(int i, int j, int n, int m){
        return (i>=0 && i<n && j<m && j>=0);
    }   

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<tuple<int,int,int, bool>, vector<tuple<int,int,int, bool>>, greater<>> heap;
        heap.push({0, 0, 0, true});
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> visited;

        while(!heap.empty()){
            auto [time, i, j, isOne] = heap.top();
            heap.pop();

            if(i==n-1 && j == m-1){
                return time;
            }

            for(auto d : dir){
                int row = i + d[0], col = j + d[1];
                if(validate(row, col, n, m) && !visited.count({row, col})){
                    heap.push({max(time, moveTime[row][col]) + (isOne?1:2), row, col, !isOne});
                    visited.insert({row, col});
                }
            }
        }
            return -1;

    }
};