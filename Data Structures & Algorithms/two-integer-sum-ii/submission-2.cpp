class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        while(i < j){
            int currSum = numbers[i] + numbers[j];
            if(currSum < target){
                i++;
            }else if(currSum > target){
                j--;
            }else{
                return {i+1,j+1};
            }
        }
        return{};
    }
};
