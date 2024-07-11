class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int n = s.length();
        string temp="";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(temp);
                
                temp = "";
            }
            else if(s[i]==')'){
                reverse(temp.begin(),temp.end());
                if(!st.empty()){
                    temp = st.top() + temp;
                    st.pop();
                }
            }
            else{
                temp+=s[i];
            }
            cout<<temp<<endl;
        }
        return temp;
    }
};