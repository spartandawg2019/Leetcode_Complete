class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, int k, string& word) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[k]) {
            return false;
        }
        if (k == word.length() - 1) {
            return true;
        }
        char cur = board[i][j];
        board[i][j] = '-';
        bool res = dfs(board, i - 1, j, k + 1, word) || dfs(board, i + 1, j, k + 1, word) || dfs(board, i, j - 1, k + 1, word) || dfs(board, i, j + 1, k + 1, word);
        board[i][j] = cur;
        return res;
    }
};
