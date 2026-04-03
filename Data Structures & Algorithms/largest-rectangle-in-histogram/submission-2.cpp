class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int,int>> stack;
        for(int i = 0; i < heights.size();i++){
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                pair<int,int> p = stack.top();
                int index = p.first;
                int height = p.second;
                res = max(res,height * (i - index));
                start = index;
                stack.pop();
            }
            stack.push({start,heights[i]});
        }
        while(!stack.empty()){
            int index = stack.top().first;
            int height = stack.top().second;
            res = max(res,height * (static_cast<int>(heights.size())-index));
            stack.pop();
        }
        return res;
    }
    
};
