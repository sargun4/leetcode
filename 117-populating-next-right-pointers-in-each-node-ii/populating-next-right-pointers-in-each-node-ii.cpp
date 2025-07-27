class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        Node* node = root;
        q.push(node);
        while(!q.empty()){
            int sz=  q.size();
            for(int i=0; i<sz; i++){
                Node* temp = q.front();
                q.pop();
                if(i<sz-1) temp->next=q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};