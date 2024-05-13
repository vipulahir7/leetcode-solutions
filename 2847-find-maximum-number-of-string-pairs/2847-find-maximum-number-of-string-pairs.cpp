class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,bool> check;
        for(int i=0;i<words.size();i++){
            check[words[i]]=true;
        }

        int count=0;

        for(int i=0;i<words.size();i++){
            string str=words[i];
            reverse(str.begin(),str.end());
            if(str==words[i]){
                continue;
            }
            if(check[str]){
                count++;
            }
        }
        return count/2;
    }
};