class Solution {
public:

    int numTrees(int n) {
        vector<int> totalTrees(n+2);
        totalTrees[0] = 1;

        for(int i=1;i<=n;i++){
            totalTrees[i] = 0;
            for(int j=0; j<i; j++){
                totalTrees[i] += totalTrees[j] * totalTrees[i-j-1];
            }
        }
        return totalTrees[n];
    }
};