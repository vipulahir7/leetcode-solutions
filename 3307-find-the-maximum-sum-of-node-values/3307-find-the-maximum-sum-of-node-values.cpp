class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        long long total=0,ben=0,minBen=LLONG_MAX,minLoss=LLONG_MAX;
        vector<int> benefits;
        for(auto ele:nums){
            total+=ele;
            if((ele^k) > ele) {
                benefits.push_back(ele);
                long long b=((ele^k)-ele);
                minBen=min(minBen,b);
                ben+=b;
            }
            else{
                minLoss=min(minLoss,(long long)(ele-(ele^k)));
            }
        }

        cout<<total<<" "<<ben<<" "<<minBen<<' '<<minLoss<<endl;
        
        if(benefits.size()%2){
            if(minBen > minLoss){
                return total+ben-minLoss;
            }
            return total+ben-minBen;
        }
        return total+ben;
    }
};