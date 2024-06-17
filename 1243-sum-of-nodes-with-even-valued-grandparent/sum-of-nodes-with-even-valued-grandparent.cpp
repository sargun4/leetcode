class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop(); 
                if(temp!=NULL && (temp->val%2)==0){
                    if(temp->left!=NULL && temp->left->left!=NULL){
                        sum=sum+temp->left->left->val;	
                    } 	
                    if(temp->left!=NULL && temp->left->right!=NULL){
                        sum=sum+temp->left->right->val;
                    }
                    if(temp->right!=NULL && temp->right->left!=NULL){
                        sum=sum+temp->right->left->val;
                    }
                    if(temp->right!=NULL && temp->right->right!=NULL){
                        sum=sum+temp->right->right->val;
                    }
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
        }
        return sum;    
    }
};