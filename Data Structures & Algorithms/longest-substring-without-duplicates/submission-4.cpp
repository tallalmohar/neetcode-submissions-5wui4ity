class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> count;
      int l = 0;
      int res = 0;
      for(int r = 0; r< s.size();r++){
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
