class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_set<int> count;
        for(int r = 0; r < s.size();r++){
            while(count.find(s[r]) != count.end()){
                count.erase(s[l]);
                l++;
            }
            count.insert(s[r]);
            res = max(res,r-l+1);
        }
        return res;
    }
};
