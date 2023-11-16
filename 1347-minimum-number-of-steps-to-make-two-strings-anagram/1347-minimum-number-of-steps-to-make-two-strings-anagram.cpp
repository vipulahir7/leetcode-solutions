class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26]={0};
        int n=s.length();
        
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[t[i]-'a']){
                arr[t[i]-'a']--;
            }
            else{
                count++;
            }
        }
        return count;
    }
};