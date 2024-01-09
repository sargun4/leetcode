class Solution:
    def isLeaf(self, node):
        if node is None:
            return False
        if node.left is None and node.right is None:
            return True
        return False
    
    def preorder(self, root, leaves):
        if root is None:
            return
        if self.isLeaf(root):
            leaves.append(root.val)
        self.preorder(root.left, leaves)
        self.preorder(root.right, leaves)
    
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        leaves1 = []
        leaves2 = []
        self.preorder(root1, leaves1)
        self.preorder(root2, leaves2)
        
        return leaves1 == leaves2
