class Solution:
    def deleteNode(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        def minnode(root):
            curr=root
            while(curr is not None and curr.left is not None):
                curr=curr.left
            return curr
        if root is None:
            return root
        if(root.val > val): #move to left subtree
            root.left=self.deleteNode(root.left,val)
        elif(root.val < val): #move to right subtree
            root.right=self.deleteNode(root.right,val)
        else: #ndoe found,del it
            if(root.right is None and root.left is None):#leaf node
                del(root)
                return None
            elif(root.right is None):#has only left child
                temp=root.left
                del(root)
                return temp
            elif(root.left is None):#has only right child
                temp=root.right
                del(root)
                return temp
            else:#node has 2 children
                #find the minimum node in the right subtree-inorder successor
                inSucc=minnode(root.right)
                #copy the information from inSucc to root
                root.val=inSucc.val
                #delete the inSucc from the right subtree
                root.right=self.deleteNode(root.right,inSucc.val)
        return root