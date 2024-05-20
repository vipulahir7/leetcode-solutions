class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string ans="";
        unordered_map<int,bool> check;
        for(int i=0;i<n;i++){
            int temp=0;
            string str=nums[i];
            for(int j=0;j<n;j++){
                if(str[n-j-1]=='1') temp+=(1<<j);
            }
            check[temp]=true;
        }
        int num=0;
        while(check[num]) num++;

        for(int j=0;j<n;j++){
            if(num&1) ans+="1";
            else ans+="0";
            num>>=1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};