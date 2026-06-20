class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int>rows(9,0);
        vector<int>colums(9,0);
        vector<int>squares(9,0);
        for (int r = 0; r < 9; ++r) {
         for (int c = 0; c < 9; ++c) {
            if(board[r][c]=='.'){
                continue;
            }

            int val = board[r][c] - '1'; // can be 0 1 2 ... 8

            if( (rows[r] & (1<<val))   || 
                (colums[c] & (1<<val)) ||
                (squares[(r/3)*3  + c/3] & (1<<val)) // ((r/3)*3 + c/3) is unique like 0 to 8
              )
              {
                return false;
              }

              rows[r] = rows[r] | (1<<val);   // 000000 -> 00001000 something like that 
              colums[c] = colums[c] | (1<<val);
              squares[(r/3)*3 + c/3] |=(1<<val);
          }


        }

        return true;


    }
};
