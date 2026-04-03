class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        int res = nums[0];
        while(l<=r){
            int m = (l+r)/2;
            if(nums[l] < nums[r]){
                res = min(nums[l],res);
                break;
            }
            res = min(nums[m],res);
            if(nums[l] <= nums[m]){
                l = m +1;
            }else{
                r = m -1;
            }
        }
        return res;
    }
};
