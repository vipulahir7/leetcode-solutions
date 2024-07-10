class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(auto l : logs){
            if(l[0] != '.') count++;
            else if(l[1] == '.') if(count) count--;
        }
        return count;
    }
};