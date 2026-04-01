# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def same_tree(r, s):
            if r is None and s is None:
                return True
            if r is None or s is None:
                return False
            if r.val != s.val:
                return False
            
            return same_tree(r.left, s.left) and same_tree(r.right, s.right)

        if root is None:
            return False
        if same_tree(root, subRoot):
            return True
        
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)