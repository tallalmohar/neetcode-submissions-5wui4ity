class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> set;
        int maxF = 0;
        int res = -1;
        int l = 0;
        for(int r = 0; r < s.size();r++){
            set[s[r]]++;
            maxF = max(maxF,set[s[r]]);
            while((r-l+1)-maxF > k){
                set[s[l]]--;l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};
