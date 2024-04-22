class Solution {
public:

    bool isPossible(long long mid,vector<int> &ranks,int cars){
        long long done=0;
        for(auto rank:ranks){
            long long temp=mid/rank;
            done+=((long long)sqrt(temp));
        }
        return done>=cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {

        long long int ans,start=0,end=*min_element(ranks.begin(),ranks.end())*(long long)cars*(long long)cars;

        while(start<=end){
            long long mid=start+(end-start)/2;

            if(isPossible(mid,ranks,cars)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};