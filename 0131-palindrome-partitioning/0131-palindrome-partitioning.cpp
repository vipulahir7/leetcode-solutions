class Solution {
public:
    
    bool isPalindrome[16][16];
    
    void fillPal(string &s){
        int n=s.size();
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(j-i<=2 && s[i]==s[j]){
                    isPalindrome[i][j]=true;
                }
                else if(s[i]==s[j] && isPalindrome[i+1][j-1]){
                    isPalindrome[i][j]=true;
                }
            }
        }   
    }
    
    vector<vector<string>> partition(string s) {
        
    fillPal(s);
    vector<vector<string>> res;
    vector<string> ans;
    fun(0, s, ans, res);
    return res;
}

void fun(int ind, string s, vector<string>& ans, vector<vector<string>>& res) {
    if (ind == s.size()) {
        res.push_back(ans);
        return;
    }
    for (int i = ind; i < s.size(); ++i) {
        if (isPalindrome[ind][i]) {
            ans.push_back(s.substr(ind, i - ind + 1));
            fun(i + 1, s, ans, res); 
            ans.pop_back();
        }
    }
}

};