class Solution {
public:

    unordered_map<int,vector<int>> mp;

    void fillMap(string s){
        int n=s.length();

        for(int i=n-1;i>=0;i--){
            int num=0;
            for(int j=i;j>=0;j--){
                if(i-j>30){
                    break;
                }
                num+=(s[j]-'0')<<(i-j);
                if(s[j]-'0' || (num==0)) mp[num]={j,i};
            }
        }
    }

    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {

        fillMap(s);
        vector<vector<int>> ans;
        int q=queries.size();
        for(int i=0;i<q;i++){
            int need=queries[i][0]^queries[i][1];
            if(mp.find(need)!=mp.end()){
                ans.push_back(mp[need]);
            }
            else{
                ans.push_back({-1,-1});
            }
        }
        return ans;
    }
};