class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start,end;

        unordered_map<int,int> ans;

        vector<int> temp = people;
        sort(temp.begin(), temp.end());

        for(auto f: flowers){
            start.push_back(f[0]);
            end.push_back(f[1]);
        }   

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int time=0, idx=0, c=0, si = 0, ei = 0;

        while(idx<temp.size()){
            int nxt = temp[idx];
            while(si < start.size() && start[si] <= nxt){
                c++;
                si++;
            } 
            while(ei<end.size() && end[ei] < nxt){
                ei++;
                c--;
            }

            ans[nxt] = c;
            idx++;
        }
        vector<int> a;
        for(auto n: people){
            a.push_back(ans[n]);
        }
        return a;


    }
};