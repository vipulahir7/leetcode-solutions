class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& a, vector<int>& b) {
        int h=1, v=1;
        int i=0,j=0;
        long long ans = 0;
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        while(i<m-1 && j<n-1){
            if(a[i]>=b[j]){
                ans += v*a[i];
                i++;
                h++;
            }
            else if(b[j] > a[i]){
                ans += h*b[j];
                v++;
                j++;
            }
        }
        while(i<m-1){
            ans += v*a[i];
            i++;
        }
        while(j< n-1){
            ans += h*b[j];
            j++;
        }
        return ans;
    }
};