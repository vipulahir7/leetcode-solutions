class Solution {
public:
    int maxPower(string s) {
        char ch=s[0];
        int len=1,ans=1,n=s.length();
        for(int i=1;i<n;i++){
            if(ch==s[i]){
                len++;
                ans=max(ans,len);
            }
            else{
                len=1;
                ch=s[i];
            }
        }
        return ans;
    }
};