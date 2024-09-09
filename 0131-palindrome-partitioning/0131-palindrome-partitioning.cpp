class Solution {
public:

    vector<vector<string>> ans;
    vector<string> b;

    bool check(string s){
        if(s.length() == 0) return true;
        int i=0, j = s.length()-1;

        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void func(string s, int i, string current){
        if(i>s.size()) return;
        if(i==s.size()){
            if(current == ""){
                ans.push_back(b);   
            }
            return;
        }

        current += s[i];

        if(check(current)){
            b.push_back(current);
            func(s, i+1, "");
            b.pop_back();
        }
        func(s, i+1, current);    
    }

    vector<vector<string>> partition(string s) {
        func(s, 0, "");
        return ans;
    }
};