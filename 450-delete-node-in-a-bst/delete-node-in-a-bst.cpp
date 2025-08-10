class Solution {
public:
    TreeNode* minnode(TreeNode*root){
        TreeNode* curr=root;
        while(curr!=NULL && curr->left!=NULL){
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root==NULL) return root;
        if(root->val > val){ //move to left subtree
            root->left = deleteNode(root->left,val);
        }else if(root->val < val){ //move to right subtree
            root->right = deleteNode(root->right,val);
        }else{//ndoe found,del it
            if(root->left == NULL && root->right==NULL){ //no children-leafnode
                delete root;
                return NULL;
            }else if(root->left == NULL){//only right childexists
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(root->right == NULL){//only left childexists
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else{//has 2 children
                TreeNode* inSucc = minnode(root->right);//inorderSUcc
                root->val = inSucc->val;//copy the value of inorder succes to root node 
                root->right = deleteNode(root->right,inSucc->val); //remove inorder succes
            }
        }
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* maxnode(TreeNode* root){
//         TreeNode* curr=root;
//         while(curr!=NULL && curr->right!=NULL){
//             curr=curr->right;
//         }
//         return curr;
//     }
//     TreeNode* deleteNode(TreeNode* root, int val) {
//         if(root==NULL) return root;
//         if(root->val > val){
//             root->left=deleteNode(root->left,val);
//         }else if(root->val< val){
//             root->right=deleteNode(root->right,val);
//         }else{//TreeNode found,del it
//             if(root->right == NULL && root->left == NULL) { // leaf TreeNode
//                 delete root;
//                 return NULL;
//             } else if (root->right == NULL) {
//                 TreeNode* temp = root->left;
//                 delete root;
//                 return temp;
//             } else if (root->left == NULL) {
//                 TreeNode* temp = root->right;
//                 delete root;
//                 return temp;
//             } else { // TreeNode has 2 children
//                 TreeNode* inorderPred = maxnode(root->left);
//                 root->val = inorderPred->val;
//                 root->left = deleteNode(root->left, inorderPred->val);
//             }
//         }
//         return root;
//     }
// };