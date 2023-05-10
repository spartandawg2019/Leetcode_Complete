# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.max_sum = float('-inf')
        
        def gain_from_subtree(node: TreeNode) -> int:
            if not node:
                return 0
            
            left_gain = max(gain_from_subtree(node.left), 0)
            right_gain = max(gain_from_subtree(node.right), 0)
            curr_sum = node.val + left_gain + right_gain
            self.max_sum = max(self.max_sum, curr_sum)
            return node.val + max(left_gain, right_gain)
        
        gain_from_subtree(root)
        return self.max_sum
