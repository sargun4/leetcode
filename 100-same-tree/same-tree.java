class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null && q==null) return true;
        if(p==null || q==null) return false; 
        if(p.val!=q.val) return false;
        return isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
    }
}
// class Solution {
//     public boolean isSameTree(TreeNode p, TreeNode q) {
//        if (p == null || q == null) { return p == q;}        
//         return (p.val == q.val) && isSameTree(p.left, q.left) && isSameTree(p.right, q.right); 
//     }
// }

// class Solution {
//     public boolean isSameTree(TreeNode p, TreeNode q) {
//         //base case
//         if( p == null && q == null)
//             return true;
//         if(p == null || q == null){
//             return false;
//         }
        
//         //checking if both right and left nodes are equal as well as the root
//         if(p != null && q != null){
//             return (p.val == q.val) && isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
//         }
//         return false;
        
//     }
// }