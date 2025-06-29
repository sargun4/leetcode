//To find all the possible permutations of BSTs with n nodes, we can lock one node as the root node & split n - 1 nodes between the left and right subtrees in all the possible ways.
// we place a node with value i as the root node and place i - 1 nodes having values from 1 to i - 1 in the left subtree. (If i == 1, the left child is null). Similarly, we place the remaining n - i nodes having values from i + 1 to n in the right subtree. (If i == n, the right child is null).
// recursion as we are breaking down a problem with n nodes to smaller, repetitive subproblems with i - 1 and n - i nodes (for i = 1 till n) to compute the answer for n nodes.
//so build the tree recursively for left and right subtrees rooted at i as leftSubTree = bst(start, i-1) and rightSubtree = bst(i + 1, end)
//Now connect leftSubTree & rightSubTree with root & add this tree(rooted at i) to the ans list
class Solution {
public:
    vector<TreeNode*> buildTree(int start,int end){
        vector<TreeNode*> ans;
        //if start>end, then subtree will be empty so add NULL and return 
        if(start>end){
            ans.push_back(NULL); 
            return ans;
        }
        //iter thru all vals frm start to end
        for(int i=start;i<=end;i++){
            vector<TreeNode*> l=buildTree(start,i-1);//lft subtree
            vector<TreeNode*> r=buildTree(i+1,end);//right subtree
            //connect all l n r subtrees to ith root
            for(int j=0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                    TreeNode* root=new TreeNode(i);//root=i
                    root->left=l[j];//connect l subtree 
                    root->right=r[k];//r
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n){
        return buildTree(1,n);
    }
};