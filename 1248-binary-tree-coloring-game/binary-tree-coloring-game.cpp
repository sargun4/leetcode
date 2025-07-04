//need to pick a blue so that red cant expand too much : ctr(blue) > ctr(red) =>to win
class Solution {
public:
    TreeNode* rootx;//node w value x (red node)
    unordered_map<int, TreeNode*> map;//{child_val:parent}
    // BFS to count size of subtree/region starting from given node
    int bfs(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*> q; 
        q.push(root);
        int ctr=0;
        while(!q.empty()){
            auto curr=q.front();q.pop();
            int val=curr->val;
            curr->val=0;//mark node as vis=0
            ctr++;
            //go to unvis neighs- l,r children n parent
            if(curr->left && curr->left->val!=0) q.push(curr->left);
            if(curr->right && curr->right->val!=0) q.push(curr->right);
            if(map[val] && map[val]->val!=0) q.push(map[val]);
        }
        return ctr;//size of subtree of curr node 
    }
    // Build parent map and locate the red node
    void preorder(TreeNode* root, int x) {
        if (!root) return;

        if (root->val == x) rootx = root;

        if (root->left) map[root->left->val] = root;
        if (root->right) map[root->right->val] = root;

        preorder(root->left, x);
        preorder(root->right, x);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x){
        // Step 1: preprocess to find red node and parent links
        preorder(root,x);
        map[root->val]=NULL;//root has no parent
        // Step 2: block red node (player 1 starts here)
        rootx->val = 0;
        // Step 3: count all 3 disjoint zones via BFS
        int a=bfs(map[x]);//parent side
        int b=bfs(rootx->left);//l subtree
        int c=bfs(rootx->right);//r subtree
        //Case1: Pick parent of x as blue: ctr(left subtree) + ctr(right subtree) + 1(for x) < ctr(Parent);
        // Case2: Pick left of x as blue: ctr(parent subtree) + ctr( right subtree) + 1 < ctr( Left)
        // Case3: Pick right of x as blue: ctr(left subtree) + ctr( parent subtree) + 1< ctr( Right)
        // If any of case becomes true, we win
        // else we lose
        if(a+b+1<c) return true;
    
        if(b+c+1<a) return true;
        
        if(c+a+1<b) return true;
        
        return false;
    }
};
