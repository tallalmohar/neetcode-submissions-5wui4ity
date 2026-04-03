class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        /*
        int i =0; 
        while(i < nums.size()){
            int j = i + 1;
            while(j < nums.size()){
                if(nums[i] > nums[j]){
                    swap(nums[i],nums[j]);
                    
                }
                j++;
            }
            i++;
        }
        int a = 0;
        int b = a+1;
        while(b != nums.size()-1){
            if(nums[a] == nums[b]){
                return true;
            }
            a++;
            b++;
        }
        return false;
        */

        //time complexity of O(n) - we looped through the entire array once
        //space complexity of O(n) -  we had to use more memory to store the hashmap
        unordered_set<int> seen;
        for(int i =0; i < nums.size();i++){
            if(seen.count(nums[i])){ // check if the num has been seen in the set before
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;


    }
};
