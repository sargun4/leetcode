class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q=new LinkedList<TreeNode>();
        List<List<Integer>> ans=new LinkedList<List<Integer>>();
        if(root==null) return ans;
        q.add(root);
        while(!q.isEmpty()){
            int lvl=q.size();
            List<Integer> sublist=new LinkedList<Integer>();
            for(int i=0;i<lvl;i++){
                if(q.peek().left!=null) q.add(q.peek().left);
                if(q.peek().right!=null) q.add(q.peek().right);
                sublist.add(q.remove().val);
            }
            ans.add(sublist);
        }
        return ans;
    }
}
// class Solution {
//     public List<List<Integer>> levelOrder(TreeNode root) {
//         Queue<TreeNode> q = new LinkedList<>();
//         List<List<Integer>> finalAns = new ArrayList<List<Integer>>();
//         if(root==null){
//             return finalAns;
//         }
//         q.add(root);
//         while(!q.isEmpty()){
//             int levels = q.size();
//             List<Integer> subLevels = new ArrayList<>();
//             for(int i=0;i<levels;i++){
//                 if(q.peek().left!=null){
//                     q.add(q.peek().left);
//                 }
//                 if(q.peek().right!=null){
//                     q.add(q.peek().right);
//                 }
//                 subLevels.add(q.remove().val);
//             }
//             finalAns.add(subLevels);
//         }
//         return finalAns;
//     }
// }
// // Declare a Queue named q that will be used for level-by-level traversal of the binary tree.
// // Declare a List of Lists of Integers named finalAns to store the final result.
// // Check if the root of the binary tree is null. If it is, return the empty list of lists.
// // Add the root node of the binary tree to the queue.
// // While the queue is not empty, perform the following steps for each level of the tree:
// // Get the size of the current level of the queue.
// // Create a new list to store the values of the current level.
// // For each node in the current level of the queue, add its left and right children (if they exist) to the end of the queue and add its value to the list of values for the current level.
// // Add the list of values for the current level to the final result list.
// // Return the final result list of lists of values for each level of the binary tree.