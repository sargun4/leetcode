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
// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(!root || !root->left) return root;
//         //trav each lvl using bfs and connect the next ptrs
//         queue<Node*> q;
//         q.push(root);
//         q.push(NULL);
//         Node* prev=NULL;
//         while(!q.empty()){
//             Node* curr=q.front(); q.pop();
//             int len=q.size();
//             if(curr==NULL){
//                 if(len==0){
//                     break;
//                 }else{
//                     q.push(NULL);
//                 }
//             }else{
//                 if(curr->left){
//                     q.push(curr->left);
//                 }
//                 if(curr->right){
//                     q.push(curr->right);
//                 }
//                 if(prev!=NULL){
//                     prev->next=curr;
//                 }
//             }
//             prev=curr;
//         }
//         return root;
//     }
// };