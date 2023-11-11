class Solution {
public:

    void solve(string digits,int index,string output,string mapping[],vector<string>& ans){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }       

        int number=digits[index]-'0';
        string value=mapping[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,index+1,output,mapping,ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output;
        int index=0;
        solve(digits,index,output,mapping,ans);
        return ans;
    }
};