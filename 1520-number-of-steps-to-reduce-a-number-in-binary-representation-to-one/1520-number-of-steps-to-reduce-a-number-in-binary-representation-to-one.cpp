class Solution {
public:
    int numSteps(string s) {
        bool isGot = false;
        int count = 0, n = s.length();
        for(int i = n-1; i>0; i--){
            if(s[i]=='1'){
                if(isGot){
                    count++;
                }
                else{
                    isGot=true;
                    count+=2;
                }
            }
            else{
                if(isGot){
                    count+=2;
                }
                else{
                    count++;
                }
            }
        }
        return count + isGot;
    }
};