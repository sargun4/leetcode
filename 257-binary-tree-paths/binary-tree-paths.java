// class Solution {
// //Recursion
// public List<String> binaryTreePaths(TreeNode root) {
//     List<String> sList=new LinkedList<String>();
//     //String s=new String();
//     if (root==null) return sList;
//     if (root.left==null && root.right==null) {
//         sList.add(Integer.toString(root.val));
//         return sList;
//     }
    
//     for (String s: binaryTreePaths(root.left)) {
//         sList.add(Integer.toString(root.val)+"->"+s);
//     }
//     for (String s: binaryTreePaths(root.right)) {
//         sList.add(Integer.toString(root.val)+"->"+s);
//     }
//     return sList;
// }
// class Solution {
//     public List<String> binaryTreePaths(TreeNode root) {
//         List<String> ans = new ArrayList<String>();
//         if (root != null) searchBT(root, "", ans);
//         return ans;
//     }
//     private void searchBT(TreeNode root, String path, List<String> ans) {
//         if (root.left == null && root.right == null) ans.add(path + root.val);
//         if (root.left != null) searchBT(root.left, path + root.val + "->", ans);
//         if (root.right != null) searchBT(root.right, path + root.val + "->", ans);
//     }
// }
class Solution {
    public void helper(TreeNode root,List<String> ans,String s){
        if(root==null) return;
        if(root.left==null && root.right==null){//leaf node reached
            s+=root.val;
            ans.add(s);
            return;
        }
        helper(root.left,ans,s+root.val+"->");
        helper(root.right,ans,s+root.val+"->")
        ;
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans=new ArrayList<>();    
        helper(root,ans,"");
        return ans;
    }
}