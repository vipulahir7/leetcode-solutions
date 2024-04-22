class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            arr[i]=(dist[i]/speed[i])+(dist[i]%speed[i]!=0);
        }

        sort(arr.begin(),arr.end());
        long long ans=1;
        for(int i=1;i<n;i++){
            if(arr[i]<=ans){
                return ans;
            }
            ans++;
        }
        return ans;
    }
};