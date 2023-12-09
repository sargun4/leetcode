//MORRIS TRAV-O(n)
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> arr = new ArrayList<>();
        TreeNode curr=root;
        while(curr!=null){
            if(curr.left!=null){//find predeccesor
                TreeNode pred=curr.left;
                while(pred.right!=null && pred.right!=curr){
                    pred=pred.right;
                }
                if(pred.right==null){//conect pred's right' w curr
                    pred.right=curr;
                    curr=curr.left;
                }if(pred.right==curr){//remove link bw pred n curr
                    pred.right=null;
                    arr.add(curr.val);
                    curr=curr.right;
                }
            }
            else{//curr.left==null, no pred
                arr.add(curr.val);
                curr=curr.right;
            }
        }
        return arr;
    }
}

// // //rec
// // class Solution {
// //     List<Integer> ans = new ArrayList<>();
// //     public List<Integer> inorderTraversal(TreeNode root) {
// //         if (root == null) return ans;
// //         inorderTraversal(root.left);
// //         ans.add(root.val);
// //         inorderTraversal(root.right);
// //         return ans;
// //     }
// // }

// //iter-using stack
// class Solution {
//     public List<Integer> inorderTraversal(TreeNode root) {
//         List<Integer> list = new ArrayList<Integer>();

//         Stack<TreeNode> stack = new Stack<TreeNode>();
//         TreeNode cur = root;

//         while(cur!=null || !stack.empty()){
//             while(cur!=null){
//                 stack.add(cur);
//                 cur = cur.left;
//             }
//             cur = stack.pop();
//             list.add(cur.val);
//             cur = cur.right;
//         }

//         return list;
//     }
// }