//bfs
// #O(tree*subtree)
class Solution{
public:
    bool sametree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val!=subRoot->val) return false;
        return sametree(root->left,subRoot->left) && sametree(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root||!subRoot){//if either is null not both atsame time
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
            //if val of curr node matches val of root of subtree ,
            // check if subtree starting frm curr node is identical to given subtree
            if(curr->val==subRoot->val){
                if(sametree(curr,subRoot)){
                    return true;
                }
            }
        } 
        return false;//if no subtree found return false;
    }
};

// //dfs
// // #O(tree*subtree)
// class Solution{
// public:
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(!root||!subRoot){//if either is null not both atsame time
//             return false;
//         }
//         if(sameTree(root,subRoot)) {
//             return true;
//         }
//         return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
//     }
//     bool sameTree(TreeNode* root, TreeNode* subRoot) {
//         if (!root && !subRoot) { //if both are null
//             return true;
//         }
//         if (root && subRoot && root->val == subRoot->val) {
//             return (sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right));
//         }
//         return false;
//     }
// };
