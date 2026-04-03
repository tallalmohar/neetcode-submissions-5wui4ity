class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        Arrays.fill(res,1);
        for(int i = 1; i < nums.length;i++){
            res[i] = nums[i-1] * res[i-1];
        }
        int pfix = 1;
        for(int i = res.length-1;i >= 0;i--){
            res[i] *= pfix;
            pfix *= nums[i];
        }
        return res;
    }
}  
