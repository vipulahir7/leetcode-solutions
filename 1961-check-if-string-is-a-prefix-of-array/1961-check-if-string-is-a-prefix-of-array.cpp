class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp="";
        for(auto i:words){
            temp+=i;
            if(temp==s){
                return true;
            }
            else if(temp.length() > s.length()){
                break;
            }
        }
        return false;
    }
};