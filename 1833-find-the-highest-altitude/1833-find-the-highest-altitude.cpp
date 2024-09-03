class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int c =0, a =0 ;
        for(auto g : gain){
            c += g;
            a = max(a, c);
        }
        return a;
    }
};