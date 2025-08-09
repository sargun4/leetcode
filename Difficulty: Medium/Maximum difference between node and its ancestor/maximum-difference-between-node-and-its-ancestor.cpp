class Solution {
public:
    void solve(int maxval,Node*root,int&res){
        if(!root) return;
        //diff bw largest ancestor val & curr node's val
        int temp=maxval-(root->data);
    //update max diff if curr diff is larger
        res=max(res,temp);
        
        maxval=max(maxval,root->data);
        solve(maxval,root->left,res);
        solve(maxval,root->right,res);
    }

    int maxDiff(Node* root) {
        int res=INT_MIN;
      // Start DFS traversal from root’s children
        // Passing root->data as the initial max ancestor value
        // because the root is the topmost ancestor in the path
        solve(root->data,root->left,res);
        solve(root->data,root->right,res);
        return res;

    }
};
