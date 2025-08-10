 
class Solution {
public:
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int instart,int inend,int poststart,int postend){
        if(instart>inend) return NULL;//no elmnts left in this subtree
        //in postorder, last elmnt in curr range is root of subtree
        TreeNode* root=new TreeNode(postorder[postend]);
        //find idx of this root in inorder to split left/rigt subtrees
        int i=instart;
        for(;i<=inend;i++){
            if(inorder[i]==root->val) break;
        }
        int leftsize=i-instart;//no of nodes in l subtree
        int rightsize=inend-i;//no of nodes in r subtree
        //build l subtree
        //l subtree inoder range- instart to (i-1)
        //l subtree postorder range- poststart to (poststart+lsize-1)
        root->left=solve(inorder,postorder,instart,i-1,poststart,poststart+leftsize-1);
        //build r subtree
        //l subtree inoder range- i+1 to inend
        //r subtree postorder range- (postend-rightisze) to (postend-1)
        root->right=solve(inorder,postorder,i+1,inend,postend-rightsize,postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int instart=0;
        int inend=n-1;
        int poststart=0;
        int postend=n-1;
        return solve(inorder,postorder,instart,inend,poststart,postend);
    }
};