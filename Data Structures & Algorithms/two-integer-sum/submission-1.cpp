class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> set; //making the set
      //looping through the entire array to insert values into set
      //value:index
      for(int i =0;i < nums.size();i++){
        set[nums[i]] = i;
      }
      
      for(int i =0;i < nums.size();i++){
        int diff = target-nums[i]; //diff or target and current index
        if(set.count(diff) && set[diff] != i){//if difference is in the set and its not the current index
            return {i,set[diff]};// return the index and the index of diffrence
        }
      }
      return {};// else return nothing! 

      //Time complexity is O(n)
      //Space complexity is O(n)
    }
};
