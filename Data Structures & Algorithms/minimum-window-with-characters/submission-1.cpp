class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())return "";
        unordered_map<char,int> window,countT;
        for(char c : t){
          countT[c]++;
        }
        int keep = 0, need = countT.size();
        int resLen = INT_MAX;
        pair<int,int> res = {-1,-1};
        int l = 0;
        for(int r = 0; r < s.size();r++){
          char c = s[r];
          window[c]++;
          if(countT.count(c) && countT[c] == window[c]){
            keep++;
          }
          while(keep == need){
            if((r-l+1) < resLen){
              resLen = r-l+1;
              res = {l,r};
            }
            window[s[l]]--;
            if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
              keep--;
            }
            l++;
          }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first,resLen);
    }
};
