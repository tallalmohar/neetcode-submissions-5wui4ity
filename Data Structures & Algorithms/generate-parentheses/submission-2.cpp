class Solution {
public:
    void backtracking(int openN, int closedN, int n, vector<string>& res, string& s){
        if(openN == n && closedN == openN){
            res.push_back(s);
            return;
        }
        if(openN < n){
            s += '(';
            backtracking(openN+1,closedN,n,res,s);
            s.pop_back();
        }
        if(openN > closedN){
            s += ')';
            backtracking(openN,closedN+1,n,res,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> res;
       string s;
       backtracking(0,0,n,res,s);
       return res; 
    }
};
