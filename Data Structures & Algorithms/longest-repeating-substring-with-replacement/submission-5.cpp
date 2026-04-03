class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> set;
        int l = 0;
        int res = 0;
        int maxF = 0;
        for(int r = 0; r < s.size();r++){
            set[s[r]]++;
            maxF = max(set[s[r]],maxF);
            while((r-l+1)-maxF > k){
                set[s[l]]--;l++;
            }
            res = max(res,r-l+1);
        } 
        return res;
    }
};
