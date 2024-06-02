class Compare {
public:
    bool operator()(pair<char,int> below, pair<char,int> above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
};
class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        bool arr[100001]={false};
        priority_queue<pair<char,int>,vector<pair<char,int>>, Compare> pq;

        pq.push({s[0],0});

        for(int i=1;i<n;i++){
            if(s[i]=='*'){
                arr[i]=true;
                auto top=pq.top();
                pq.pop();
                arr[top.second]=true;
            }
            else{
                pq.push(make_pair(s[i],i));
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(!arr[i]) ans+=s[i];
        }
        return ans;
    }   
};  