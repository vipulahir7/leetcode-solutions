class DisjointSet{
    vector<int> size, parent;
    public:
    int count;

    DisjointSet(int n){
        count = n;
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int ultimateParent(int x){
        if(x == parent[x]) return x;
        return parent[x] = ultimateParent(parent[x]);
    }

    void handleUnion(int u, int v){
        int pu = ultimateParent(u);
        int pv = ultimateParent(v);
        if(pu == pv) return;

        count--;
        
        if(size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else if(size[pv] > size[pu]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet* ds = new DisjointSet(n);

        int total = connections.size();
        if(total < n-1) return -1;
        for(int i=0;i<total;i++) ds->handleUnion(connections[i][0],connections[i][1]);

        return ds->count-1;
    }
};