class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;//bfs
        q.push(root);
        bool flag=true;//for rev order
        while(!q.empty()){
            int n=q.size();//no of nodes in that lvl
            vector<int> row(n);//each row/lvl in tree
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                //position to fill node's val
                int idx=(flag) ? i:(n-1-i); //if flag is true, store in row in normal order ; else store in rev order; 
                row[idx]=node->val;//store nodes val at that idx
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            //after each lvl,alt order
            flag=!flag;
            res.push_back(row);
        }
        return res;
    }
};