class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int res = 0;
        while(l <= r){
            int area = min(heights[r],heights[l]) * (r-l);
            if(heights[r] > heights[l]){
                l++;
            }else{
                r--;
            }
            res = max(res,area);
        }
        return res;
    }
};
