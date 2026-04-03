class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        //O(n) time complexity, we get two hash maps then we 
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for(int i =0; i < s.length();i++){
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
        /*

        //nest while loops have o(n^2) time complexity 
        // We sort and compare the 2 strings
        int i = 0;
        int j;
        while(i < s.length() && i < t.length()){
            j = i +1;
            while(j < s.length() && j < t.length()){
                if(s[i] < s[j]){
                    swap(s[i],s[j]);
                }
                if(t[i] < t[j]){
                    swap(t[i],t[j]);
                }
                j++;   
            }   
            i++;
        }
        return s == t;
        */
    }
};
