class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int row=values.size();
        int col=values[0].size();
            
        priority_queue<int> pq;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                pq.push(values[i][j]);
            }
        }
        long long temp=row*col,ans=0;
        while(!pq.empty()){
            ans+=(temp*pq.top());
            temp--;
            pq.pop();
        }
        return ans;   
    }
};