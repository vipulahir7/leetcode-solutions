class Solution {
public:
    string robotWithString(string s) {
        vector<int> mini(s.length());
        stack<char> st;
        
        mini[s.length()-1] = s.length()-1;
        for(int i=s.length()-2; i>=0; i--){
            if(s[i] <= s[mini[i+1]]){
                mini[i] = i;
            }
            else{
                mini[i] = mini[i+1];
            }
        }

        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(mini[i] == i){
                ans+=s[i];
                while(!st.empty() && i+1 < s.length() && st.top() <= s[mini[i+1]]){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()) ans+=st.top(), st.pop();
        return ans;
    }
};