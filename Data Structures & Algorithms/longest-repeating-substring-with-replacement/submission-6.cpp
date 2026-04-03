class Solution {
public:
    int characterReplacement(string s, int k) {
     unordered_map<char,int> map;
     int l = 0;
     int res = 0;
     int maxF = 0;
     for(int r = 0;r < s.size();r++){
        map[s[r]]++;
        maxF = max(map[s[r]],maxF);
        while((r-l+1)-maxF > k){
            map[s[l]]--;
            l++;
        }
        res = max(r-l+1,res);
     }   
     return res;
    }
};
