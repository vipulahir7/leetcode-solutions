class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
    for(int i=0;s[i]!='\0';i++){
        if(!st.empty()&&(s[i]-st.top()==2||s[i]-st.top()==1)){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    return !st.size();
    }
};