class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;//hash map of value->frequency
        vector<vector<int>> freq(nums.size()+1);  // vector of vectors for freq.
        //freq[1] -> all nums that appear once
        for(int n: nums){
            count[n] = 1+count[n];
        }
        for(const auto& entry: count){
            freq[entry.second].push_back(entry.first);
        }
        
        vector<int> res;
        for(int i = freq.size()-1; i > 0; --i){
            for(int n:freq[i]){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};
