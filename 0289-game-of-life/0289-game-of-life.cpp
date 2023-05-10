class Solution {
public:
void gameOfLife(vector<vector<int>>& board) {
int m = board.size();
int n = board[0].size();
for(int i = 0; i < m; i++) {
for(int j = 0; j < n; j++) {
int live_neighbors = 0;
for(int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) {
for(int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++) {
live_neighbors += board[x][y] & 1;
}
}
live_neighbors -= board[i][j] & 1;
if((board[i][j] & 1) && (live_neighbors == 2 || live_neighbors == 3)) board[i][j] |= 2;
if(!(board[i][j] & 1) && live_neighbors == 3) board[i][j] |= 2;
}
}
for(int i = 0; i < m; i++) {
for(int j = 0; j < n; j++) {
board[i][j] >>= 1;
}
}
}
};