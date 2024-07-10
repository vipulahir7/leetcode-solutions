class Solution {
public:
    int numSteps(string s) {
        bool isGot = false;
        int count = 0, n = s.length();
        for(int i = n-1; i>0; i--){
            if(isGot){
                count++;
                if(s[i]=='0') count++;
            }
            else if(s[i]=='1'){
                isGot = true;
                count+=2;
            }
            else{
                count++;
            }
            
        }
        return count + isGot;
    }
};