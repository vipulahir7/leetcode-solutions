class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.length(),m=t.length();
            
        int i=0,j=0;
        while(i<n && j<m){
            if(t[j]==s[i]){
                j++;
            }
            i++;
        }
        return m-j;
    }
};