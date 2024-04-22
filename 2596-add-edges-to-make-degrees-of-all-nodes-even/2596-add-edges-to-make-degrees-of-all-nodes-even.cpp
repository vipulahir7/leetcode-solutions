#include<bits/stdc++.h>

class Solution {
public:

    bool isPossible(int n, vector<vector<int>>& edges) {

        unordered_map<int,unordered_map<int,bool>> adj;

        int size=edges.size();

        for(int i=0;i<size;i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u][v]=true;
            adj[v][u]=true;
        }

        vector<int> odds;
        for(auto i : adj){
            if(i.second.size() % 2){
                odds.push_back(i.first);
            }
        }

        if(odds.size() > 4){
            return false;
        }
        if(odds.size()==0){
            return true;
        }

        if(odds.size()==4){
            int a=odds[0],b=odds[1],c=odds[2],d=odds[3];

            if((adj[a].find(b) == adj[a].end() && adj[c].find(d)==adj[c].end()) ||
            (adj[a].find(c) == adj[a].end() && adj[b].find(d)==adj[b].end())    ||
            (adj[a].find(d) == adj[a].end() && adj[b].find(c)==adj[b].end())
                ){
                    return true;
                }
        }
        if(odds.size()==2){
            for(int i=1;i<=n;i++){
                if(adj.find(i)==adj.end()) return true;

                if(adj[i].find(odds[0])==adj[i].end() &&
                adj[i].find(odds[1])==adj[i].end() ){
                    return true;
                }
            }
        }
        return false;

    }
};