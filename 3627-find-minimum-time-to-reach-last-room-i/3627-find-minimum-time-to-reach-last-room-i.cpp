class Solution {
public:

    bool validate(int i, int j, int n, int m){
        return (i>=0 && i<n && j<m && j>=0);
    }

    void solve(int i, int j, int time,int n, int m, vector<vector<int>> & minTime, vector<vector<int>>& moveTime){
        
        if(validate(i+1, j, n, m) && max(moveTime[i+1][j], time)+1 < minTime[i+1][j]){
            minTime[i+1][j] = max(moveTime[i+1][j], time)+1;
            solve(i+1, j, max(moveTime[i+1][j], time)+1, n, m, minTime, moveTime);
        }
        if(validate(i-1, j, n, m) && max(moveTime[i-1][j], time)+1 < minTime[i-1][j]){
            minTime[i-1][j] = max(moveTime[i-1][j], time)+1;
            solve(i-1, j, max(moveTime[i-1][j], time)+1, n, m, minTime, moveTime);
        }
        if(validate(i, j+1, n, m) && max(moveTime[i][j+1], time)+1 < minTime[i][j+1]){
            minTime[i][j+1] = max(moveTime[i][j+1], time)+1;
            solve(i, j+1, max(moveTime[i][j+1], time)+1, n, m, minTime, moveTime);
        }
        if(validate(i, j-1, n, m) && max(moveTime[i][j-1], time)+1 < minTime[i][j-1]){
            minTime[i][j-1] = max(moveTime[i][j-1], time)+1;
            solve(i, j-1, max(moveTime[i][j-1], time)+1, n, m, minTime, moveTime);
        }
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));

        solve(0, 0, 0,n,m, minTime, moveTime);
        return minTime[n-1][m-1];
    }
};