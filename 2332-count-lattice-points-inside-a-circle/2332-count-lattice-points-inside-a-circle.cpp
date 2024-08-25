class Solution {
public:
    int countLatticePoints(vector<vector<int>>& c) {
        set<pair<int,int>> s;
        for(auto v : c){
            int a = v[0], b=v[1], r=v[2];
            for(int x=-r; x<=r; x++){
                for(int y=-r; y<=r; y++){
                    if((x*x) + (y*y) <= (r*r)){
                        s.insert({x+a, y+b});
                    }
                }
            } 
        }

        return s.size();
    }
};