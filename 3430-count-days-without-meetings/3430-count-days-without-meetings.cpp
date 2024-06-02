class Solution {
public:


    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
        int ans=(meetings[0][0]-1);
        int maxEnd=meetings[0][1];

        for(int i=1;i<n;i++){
            if(meetings[i][0] > maxEnd){
                ans+=(meetings[i][0]-maxEnd-1);
                maxEnd=meetings[i][1];
            }
            else if(meetings[i][1] > maxEnd){
                maxEnd=meetings[i][1];
            }
        }
        ans+=(days-maxEnd);
        return ans;
    }
};