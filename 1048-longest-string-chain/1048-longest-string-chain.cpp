class Solution {
public:
    static bool cmp(string &a,string &b){
        return a.size()<b.size();
    }

    bool check(string a,string b){
        int i=0,j=0,n=a.size();
        while(i<n && j<n-1){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==n-1){
            return true;
        }
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        int ans=1,n=words.size();
        vector<int> temp(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=i-1;(j>=0 && words[j].size()+1>=words[i].size());j--){                
                if( words[j].size() != words[i].size() && check(words[i],words[j]) && temp[j]+1 > temp[i]){
                    temp[i]=temp[j]+1;
                }
            }
            ans=max(temp[i],ans);
        }
        return ans;
    }
};