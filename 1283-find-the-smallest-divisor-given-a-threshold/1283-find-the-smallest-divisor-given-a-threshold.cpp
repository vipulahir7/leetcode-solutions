class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
            
        int start=1,end=*max_element(nums.begin(),nums.end()),n=nums.size();
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            int temp=0;
            for(int i=0;i<n;i++){   
                temp+=(nums[i]/mid)+(nums[i]%mid!=0);
            }
            
            if(temp<=threshold){
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