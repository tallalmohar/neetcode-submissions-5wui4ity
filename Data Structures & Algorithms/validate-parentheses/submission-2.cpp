class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> set{
            {')','('},
            {']','['},
            {'}','{'},
        };
        stack<char> stack;
        for(char c : s){
            if(set.count(c)){
                if(!stack.empty() && stack.top() == set[c]){
                    stack.pop();
                }else{
                    return false;
                }
            }else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
