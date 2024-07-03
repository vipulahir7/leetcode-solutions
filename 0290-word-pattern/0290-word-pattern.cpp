class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> mp;
        map<string,bool> mp2;
        int idx = 0;
        for(int i = 0; i<pattern.size(); i++){

            string str="";
            while(idx<s.size() && s[idx]!=' '){
                str+=s[idx];
                idx++;
            }
            idx++;
            if(mp.find(pattern[i])!=mp.end() && mp[pattern[i]] != str){
                return false;
            }
            else if(mp.find(pattern[i])==mp.end()){
                if(mp2.find(str) != mp2.end()) return false;
                mp2[str]=true;
                mp[pattern[i]] = str;
            }
        }

        if(idx != s.size()+1) return false;
        return true;
    }
};