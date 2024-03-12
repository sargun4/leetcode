//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
//GFG  
#include <bits/stdc++.h>
using namespace std;
 
void preorder(Node* root,unordered_map<Node*,Node*> &parents){
    if(root==NULL) return;
    if(root->left) parents[root->left]=root;
    if(root->right) parents[root->right]=root;
    preorder(root->left,parents);
    preorder(root->right,parents);
}
int kthAncestor(Node*root, int k, int node){
    unordered_map<Node*,Node*> parents;//store{node:parent}
    preorder(root,parents);
    Node* curr=NULL;
    for(auto it:parents){
        Node* parent=it.second;
        Node* child=it.first;
        if(child->data==node){
            curr=child;
            break;
        }
    }
    if(curr==NULL) return -1;
    else{
        while(k>0){
            k--;
            if(parents.find(curr)==parents.end()){
                return -1;
            }else{
                curr=parents[curr];
            }
        }
        return curr->data;
    }
}

// Node* search(Node*root,int target){
//     if(root==NULL) return root;
//     if(root->data==target) return root;
//     Node* left=search(root->left,target);
//     if(left) return left;
//     Node* right=search(root->right,target);
//     if(right) return right;
// }
// void markParents(Node*root,unordered_map<Node*,Node*> &parents){
//     queue<Node*> q;
//     q.push(root);
//      parents[root] = NULL;
//     while(!q.empty()){
//         Node* curr=q.front();
//         q.pop();
//         if(curr->left){
//             q.push(curr->left);
//             parents[curr]=curr->left;
//         }
//         if(curr->right){
//             q.push(curr->right);
//             parents[curr]=curr->right;
//         }
//     }
// }
// int kthAncestor(Node*root, int k, int node){
//     unordered_map<Node*,Node*> parents;//store{node:parent}
//     markParents(root,parents);
//     unordered_map<Node*,int> vis;
//     queue<Node*> q;
//     Node* targetnode=search(root,node);
//     q.push(targetnode);
//     vis[targetnode]=1;
//     int lvl=0;
//     while(!q.empty()){
//         Node* node=q.front();
//         q.pop();
//         if(node->left && !vis[node->left]){
//             q.push(node->left);
//             vis[node->left]=1;
//         }
//         if(node->right && !vis[node->right]){
//             q.push(node->right);
//             vis[node->right]=1;
//         }
//         if(parents[node] && !vis[parents[node]]){
//             if(lvl==k) return parents[node]->data;
//             q.push(parents[node]);
//             vis[parents[node]]=1;
//         }
//         lvl++;
//     }
// }
