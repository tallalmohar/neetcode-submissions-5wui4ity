class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int res = 0;
        int l = 0;
        int maxF = 0;
        for(int i = 0; i < s.size();i++){
            count[s[i]]++;
            maxF = max(maxF, count[s[i]]);

            while((i-l+1)-maxF > k){
                count[s[l]]--;l++;
            }
            res = max(res,i-l+1);
        }
        return res;
    }
};
