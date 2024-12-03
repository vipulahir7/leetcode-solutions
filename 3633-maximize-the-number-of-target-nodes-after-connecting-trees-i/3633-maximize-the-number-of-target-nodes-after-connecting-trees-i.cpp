class Solution {
public:

    int func(int node, vector<vector<int>> &a1,int p, int k){
        int ans = 1;
        if(k > 0){
            for(auto ne : a1[node]){
                if(ne != p){
                    ans += func(ne, a1, node, k-1);
                }
            }
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size(), m = edges2.size();
        vector<int> ans (n+1, 0);

        vector<vector<int>> a1(n+1), a2(m+1);

        for(auto p: edges1){
            a1[p[0]].push_back(p[1]);
            a1[p[1]].push_back(p[0]);
        }

        for(auto p: edges2){
            a2[p[0]].push_back(p[1]);
            a2[p[1]].push_back(p[0]);
        }

        int add  = 0;
        for(int i=0; i<=m && k; i++){
            add = max(add, func(i, a2, -1, k-1));
        }
        for(int i=0; i<=n; i++){
            ans[i] =add+ func(i, a1, -1, k);
        }

        return ans;
        
    }
};