// To verify if a binary tree is perfect:
// 1. Determine the depth of the leftmost path of the tree (i.e., the depth where all leaf nodes should be).
// 2. Use DFS traversal to:
//   - Check that all leaf nodes are at the same depth
//   - Ensure all internal (non-leaf) nodes have two children

class Solution {
public:
    //get depth of the leftmost path of the tree
    int lvl(Node* root){
        int lvl=0;
        while(root){
            lvl++;
            root=root->left;//go leftmost down to leaf
        }
        return lvl;//depth of leftmost leaf
    }
    void find(Node*root,bool&ans,int depth,int lvl){
        if(!root) return;
        //1.If node is a leaf, check if it's at the correct depth
        if(!root->left && !root->right){//reached leaf node
            if(depth!=lvl){//leaf not at correct depth
                ans=false;
            }
        }
        //2.internal node w only 1child
        if(!root->left && root->right || root->left && !root->right){
            ans=false;
        }
        //rec for l n r
        find(root->left,ans,depth,lvl+1);
        find(root->right,ans,depth,lvl+1);
    }
    bool isPerfect(Node*root) {
        int depth=lvl(root);
        bool ans=true;
        find(root,ans,depth,1);//start w lvl=1
        return ans;
    }
};