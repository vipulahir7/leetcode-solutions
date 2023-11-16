class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size(),lastSeat=-1e6;
        int prevSeat=1e6;
        vector<int> next(n);
        for(int i=n-1;i>=0;i--){
            if(seats[i]){
                prevSeat=i;
            }
            else{
                next[i]=prevSeat;
            }
        }
        
        int ans=1;
            
        for(int i=0;i<n;i++){
            if(seats[i]){
                lastSeat=i;
            }   
            else{
                ans=max(ans, min(next[i]-i,i-lastSeat) );
            }
        }
        return ans;   
    }
};