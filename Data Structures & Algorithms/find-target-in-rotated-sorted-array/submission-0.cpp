class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int m = (r+l)/2;
            if(target == nums[m]){
                return m;
            }
            if(nums[m] >= nums[l]){
                if(nums[m] < target || nums[l] > target){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }else{
                if(target > nums[r] || target < nums[m]){
                    r = m - 1;
                }else{
                    l = m  + 1;
                }
            }

        }
        return -1;
    }
};
