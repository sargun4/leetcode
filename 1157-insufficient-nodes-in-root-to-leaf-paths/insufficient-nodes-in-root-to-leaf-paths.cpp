class Solution {
public:
    TreeNode* getAns(TreeNode* root, int limit, int sum) {
        if(!root) {
            return root;
        }        
         //If root is leaf then check the sum from root to leaf is less than limit or not
            // a. If less than limit then return NULL
            // B. else return root
        if(!root->left  &&  !root->right) {
            if(sum + root->val < limit) {
                return NULL;
            }else {
                return root;
            }
        }
        TreeNode* l = getAns(root->left, limit, sum + root->val);
        TreeNode* r = getAns(root->right, limit, sum + root->val);    
        if(l == NULL) {
            root->left = NULL;
        }
        if(r == NULL) {
            root->right = NULL;
        }
        if(r == NULL && l == NULL) {
            return NULL;
        }
        return root;  
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return getAns(root, limit, 0);
    }
};
// class Solution {
// public:
//     int lim; 
//     // DFS function that calculates the sum from root to that node in sum param 
//     // and returns the max sum of paths below the curr node
//     int help(TreeNode* root, int sum=0){
//         // if the curr node doesn't exist return INT_MIN
//         if(!root) return -1e9;
//         // increment sum with curr node's value
//         sum+=root->val;
//         // traverse left and right subtree and get their path sum
//         int left=help(root->left,sum);
//         int right=help(root->right,sum);
        
//         // if sum from root to curr node + the paths sum below curr node is
//         // less than the limit we delete the node
//         // make sure to check if the left or substree exist
//         if(root->left && sum+left<lim) root->left=nullptr;
//         if(root->right && sum+right<lim) root->right=nullptr;
        
//         // if dead end of the path return curr nodes value
//         if(left==-1e9 && right==-1e9) return root->val;
        
//         // else return the sum of curr node + maximum of both the paths
//         return root->val+max(left,right);
//     }
//     TreeNode* sufficientSubset(TreeNode* root, int limit) {
//         lim=limit;
//         int pathsum=help(root);
//         // check if the path below root node has path sum less than limit
//         // if lesser than return null else return root
//         if(pathsum<limit) return nullptr;
//         return root;
//     }
// };