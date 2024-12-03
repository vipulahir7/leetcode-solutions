class Solution {
public:

    int c0 = 0 , c1 = 0, co0 = 0, co1 = 0;

    void func(int i, vector<vector<int>> &adj, bool isZ, int p){
        if(isZ){
            c0++;
        }
        else{
            c1++;
        }

        for(auto ele : adj[i]){
            if(ele != p){
                func(ele, adj, !isZ, i);
            }
        }
    }

    void f(int i, vector<vector<int>> &adj, bool isZ, int p, vector<bool> & mark){
        if(isZ){
            co0++;
            mark[i] = false;
        }
        else{
            co1++;
            mark[i]=true;
        }

        for(auto ele : adj[i]){
            if(ele != p){
                f(ele, adj, !isZ, i, mark);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();

        vector<vector<int>> a1(n+1), a2(m+1);
        for(auto &v : edges1){
            a1[v[0]].push_back(v[1]);
            a1[v[1]].push_back(v[0]);
        }
        for(auto &v : edges2){
            a2[v[0]].push_back(v[1]);
            a2[v[1]].push_back(v[0]);
        }

        func(0, a2, true, -1);
        cout<<"Add : "<<max(c0, c1)<<endl;


        vector<bool> mark(n+1, false);
        f(0, a1, false, -1, mark);
        cout<<"Add : "<<max(c0, c1)<<endl;


        vector<int> ans (n+1, max(c0, c1));

        for(int i=0; i<=n; i++){
            if(mark[i]){
                ans[i] += co1;
            }
            else{
                ans[i] += co0;
            }
        }
        return ans;
    }
};