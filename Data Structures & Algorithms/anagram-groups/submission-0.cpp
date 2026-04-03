class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        for(const auto& s: strs){ //s is iterating through the entire array
            vector<int> count(26,0); // vector of ints all 0's
            for(char c : s){ // iteration through each individual char of 1 string S
                count[c-'a']++; //increment each index of each char to generate a key
            }
            string key = to_string(count[0]); // convert the first index to string and then += the rest
            for(int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s); // each unique key in the res gets an s that matches it aabb key = {2,2}
            
        }
        vector<vector<string>> result;
        for(const auto& pair: res){
            result.push_back(pair.second);
        }
        return result;
    }
};
