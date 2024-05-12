class Solution {
public:
    int dp[10001];
    int helper(int i, string &s) {
        if (i < 0) {
            return 0; //base case
        }

        if (dp[i] != -1) {
            return dp[i];  //memoization
        }
            
        int freq[26] = {0}, res = 10001;
        for (int j = i; j >= 0; j--) {
            freq[s[j] - 'a']++;
            int mini = 10001, maxi = 0;
            for (int k = 0; k < 26; k++) {
                if (freq[k]) {
                    mini = min(mini, freq[k]);
                    maxi = max(maxi, freq[k]);
                }
            }
            
            if (mini == maxi) {
                res = min(res, 1 + helper(j - 1, s));
            }
        }
        
        return dp[i] = res;  // store and return
    }
    
    int minimumSubstringsInPartition(string s) {
        memset(dp, -1, sizeof dp);  //  dp array initialization
        return helper(s.size() - 1, s); //  helper function call and return
    }
};