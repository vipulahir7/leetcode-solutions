class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> check1,check2;
            
        int n=words1.size(),m=words2.size();
        
        for(int i=0;i<n;i++){
            if(check1[words1[i]]){
                check1[words1[i]]++;
            }
            else{
                check1[words1[i]]=1;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            if(check2[words2[i]]){
                if(check2[words2[i]]==1 && check1[words2[i]]==1){
                    ans--;
                }
                check2[words2[i]]++;
            }
            else{
                check2[words2[i]]=1;
                if(check1[words2[i]]==1){
                    ans++;    
                }
            }
        }
        return ans;
    }
};