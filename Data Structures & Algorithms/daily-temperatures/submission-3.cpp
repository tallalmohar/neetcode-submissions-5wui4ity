class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<pair<int,int>> stack;
        for(int i = 0; i < temperatures.size();i++){
            int t = temperatures[i];
            while(!stack.empty() && stack.top().first < t){
                auto p = stack.top();
                stack.pop();
                res[p.second] = i -p.second;
            }
            stack.push({t,i});
        }
        return res;
    }
};
