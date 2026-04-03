class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        unordered_map<char,int> count;
        int maxF = 0;
        int res = 0;
        for(int r = 0;r < s.size();r++){
            count[s[r]]++;
            maxF = max(maxF, count[s[r]]);
            while((r-l+1)-maxF > k){
                count[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
