class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        return root is not None and ((root.left is None and root.right is None and root.val == targetSum) or self.hasPathSum(root.left, targetSum - root.val) or self.hasPathSum(root.right, targetSum - root.val))
