class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int res = 0;
        int maxF = 0;
        unordered_map<char,int> m;
        for(int r = 0;r < s.size();r++){
            m[s[r]]++;
            maxF = max(maxF,m[s[r]]);
            while((r-l+1)-maxF > k){
                m[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};
