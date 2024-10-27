class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26, 0);

        for(auto c: s){
            count[c-'a']++;
        }

        while(t--){
            vector<long long> count2(26, 0);
            for(int i=0; i<26; i++){
                int tmp = count[i];
                count2[(i+1)%26] += tmp;
                count2[(i+1)%26] %= 1000000007;
                
                if(i==25){
                    count2[(i+2)%26] += tmp;
                    count2[(i+2)%26] %= 1000000007;
                }
            }
            count = count2;
        }

        long long ans = 0 ;
        for(auto s : count){
            ans = (ans + s)%1000000007;
        }
        return (int)ans;
    }
};