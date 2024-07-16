class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1,ans=0;
       
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]>=target){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid + 1;
                ans = mid;
            }
        }
        return s;
    }
};