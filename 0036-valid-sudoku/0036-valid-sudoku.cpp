class Solution {
public:
bool isValidSudoku(vector<vector<char>>& board) {
for(int i = 0; i < 9; i++) {
unordered_set<char> rows;
unordered_set<char> cols;
unordered_set<char> cube;

        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.' && rows.count(board[i][j])) {
                return false;
            } else {
                rows.insert(board[i][j]);
            }

            if(board[j][i] != '.' && cols.count(board[j][i])) {
                return false;
            } else {
                cols.insert(board[j][i]);
            }

            int row = 3 * (i / 3) + j / 3;
            int col = 3 * (i % 3) + j % 3;

            if(board[row][col] != '.' && cube.count(board[row][col])) {
                return false;
            } else {
                cube.insert(board[row][col]);
            }
        }
    }
    return true;
}

};