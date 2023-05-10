class Solution {
    private static final int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private TrieNode root = new TrieNode();
    private boolean[][] visited;
    private int rows, cols;
    private List<String> res = new ArrayList<>();
    
    public List<String> findWords(char[][] board, String[] words) {
        if (board == null || board.length == 0 || board[0].length == 0) return res;
        
        // Build the Trie
        for (String word : words) {
            TrieNode cur = root;
            for (int i = word.length() - 1; i >= 0; i--) {
                int idx = word.charAt(i) - 'a';
                if (cur.children[idx] == null) {
                    cur.children[idx] = new TrieNode();
                }
                cur = cur.children[idx];
            }
            cur.word = word;
        }
        
        // Initialize visited array
        rows = board.length;
        cols = board[0].length;
        visited = new boolean[rows][cols];
        
        // Find words
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root);
            }
        }
        
        return res;
    }
    
    private void dfs(char[][] board, int x, int y, TrieNode cur) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y]) return;
        
        cur = cur.children[board[x][y] - 'a'];
        if (cur == null) return;
        
        if (cur.word != null) {
            res.add(cur.word);
            cur.word = null;
        }
        
        visited[x][y] = true;
        for (int[] dir : dirs) {
            int i = x + dir[0], j = y + dir[1];
            dfs(board, i, j, cur);
        }
        visited[x][y] = false;
    }
    
    private class TrieNode {
        TrieNode[] children = new TrieNode[26];
        String word;
    }
}
