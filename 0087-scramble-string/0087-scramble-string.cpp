class Solution {
public:
    unordered_map<string,bool> check;
    bool solve(string s1,string s2){
        if(s1==s2){
            return true;
        }
        if(s1.size()<=1){
            return false;
        }
        string temp=s1+" "+s2;
        if(check.find(temp)!=check.end()){
            return check[temp];
        }
        int n=s1.length();
        for(int k=1;k<n;k++){
            if((solve(s1.substr(0,k),s2.substr(n-k,k)) && solve(s1.substr(k,n-k),s2.substr(0,n-k))) || (solve(s1.substr(0,k),s2.substr(0,k)) && solve(s1.substr(k,n-k),s2.substr(k,n-k)))){
                return check[temp]=true;
            }
        }
        return check[temp]=false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};