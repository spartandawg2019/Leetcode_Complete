/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }
    
private:
    Node* build(vector<vector<int>>& grid, int x, int y, int len) {
        if (len == 1) {
            return new Node(grid[x][y], true);
        }
        
        Node* tl = build(grid, x, y, len/2);
        Node* tr = build(grid, x, y+len/2, len/2);
        Node* bl = build(grid, x+len/2, y, len/2);
        Node* br = build(grid, x+len/2, y+len/2, len/2);
        
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && 
            tl->val == tr->val && tl->val == bl->val && tl->val == br->val) {
            bool val = tl->val;
            delete tl; delete tr; delete bl; delete br;
            return new Node(val, true);
        }
        
        return new Node(false, false, tl, tr, bl, br);
    }
};
