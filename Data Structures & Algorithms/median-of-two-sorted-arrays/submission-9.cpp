class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if(A.size() > B.size())swap(A,B);
        int total = A.size() + B.size();
        int half = (total + 1)/2;

        int l = 0, r = A.size();
        while(l <= r){
            int i = (r+l)/2;
            int j = half - i;

            int ALEFT = i > 0 ? A[i-1] : INT_MIN;
            int ARIGHT = i < A.size() ? A[i] : INT_MAX;
            int BRIGHT = j < B.size()? B[j] : INT_MAX;
            int BLEFT = j > 0 ? B[j-1] : INT_MIN;
            if(ALEFT <= BRIGHT && BLEFT <= ARIGHT){
                if(total%2 != 0)return max(ALEFT,BLEFT);
                return (min(ARIGHT,BRIGHT) + max(ALEFT,BLEFT)) / 2.0;
            }else if(ALEFT > BRIGHT){
                r = i - 1;
            }else{
                l = i + 1;
            }
        }
        return -1.0;
    }
};
