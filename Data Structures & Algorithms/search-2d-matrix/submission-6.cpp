class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int ROWS = matrix.size() , COLS = matrix[0].size();

       int top = 0;
       int bot = ROWS -1;
       while(top <= bot){
        int rows = (top+bot)/2;
        if(target > matrix[rows][COLS-1]){
            top = rows + 1;
        }else if(target < matrix[rows][0]){
            bot = rows - 1;
        }else{
            break;
        }
    }
        if(top > bot)return false;

        int l = 0;
        int r = COLS -1;
        int rows = (top+bot)/2;
        while(l <= r){
            int m = (l+r)/2;
            if(target > matrix[rows][m]){
                l = m + 1;            
            }else if(target < matrix[rows][m]){
                r= m - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};
