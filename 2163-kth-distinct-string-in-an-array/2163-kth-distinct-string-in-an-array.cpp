class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> count;
        int n=arr.size();
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(count[arr[i]]==1){
                c++;
            }
            if(c==k){
                return arr[i];
            }
        }
        return "";
    }
};