// T-O(n)
// S-O(nlogn)
class Solution{
    public:
    int solve(Node*root,int &moves){
        if (root == NULL) return 0;
        // Get the height of each subtree
        int l = solve(root->left, moves);
        int r = solve(root->right, moves);
        // Use the number of nodes in left and right subtrees to calculate the move cost
        moves += abs(l)+abs(r);
        // Return the maximum of the two subtrees plus one for root node
        return (l+r+root->data)-1;
    }
    int distributeCandy(Node* root){
        int moves=0;
        solve(root,moves);
        return moves;
    }
};
