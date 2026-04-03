class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> set;
        for(int i = 0 ; i < nums.size();i++){
            int diff = target - nums[i];
            if(set.find(diff) != set.end()){
                return {set[diff],i};
            }
            set.insert({nums[i],i});
        }
        return {};
    }
};
