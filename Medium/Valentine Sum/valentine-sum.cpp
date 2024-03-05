//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
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


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/


class Solution{
    public:
    Node* search(Node* root,int target){
        if(root==NULL) return root;
        if(root->data==target) return root;
        Node* left=search(root->left,target);
        if(left) return left;
        Node* right=search(root->right,target);
        if(right) return right;
    }
    void markParents(Node* root,unordered_map<Node*,Node*> &parents){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            if(node->left){
                parents[node->left]=node;
                q.push(node->left);
            }if(node->right){
                parents[node->right]=node;
                q.push(node->right);
            }
        }
    }
    int sum_at_distK(Node* root, int target, int k){
        unordered_map<Node*,Node*> parents;//store{node:parent}
        markParents(root, parents);
        unordered_map<Node*,int> vis;
        Node* targetnode=search(root,target);
        if(targetnode==NULL) return 0;
        vis[targetnode]=1;
        queue<Node*> q;
        q.push(targetnode);
        int sum=0;
        int currlvl=0;
        while(!q.empty() && currlvl<=k){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();
                sum+=node->data;
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(parents[node] && !vis[parents[node]]){
                    vis[parents[node]]=true;
                    q.push(parents[node]);
                }
            }
            currlvl++;
        }
        return sum;
    }
};
 

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends