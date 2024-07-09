class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> v(n+1,true);
        int temp = k;
        int count = n;
        int i = 1;
        while(count>1){
            if(v[i]==true){
                temp--;
                if(temp==0){
                    temp = k;
                    v[i]=false;
                    count--;
                }
            }
            i++;
            if(i>n) i = 1;
        }
        for(int i=1;i<=n;i++){
            if(v[i]){
                return i;
            }
        }
        return 0;
    }
};