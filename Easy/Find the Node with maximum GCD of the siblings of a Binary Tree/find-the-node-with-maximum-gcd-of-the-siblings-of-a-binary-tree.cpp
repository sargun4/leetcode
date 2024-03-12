//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
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
    Node *root = new Node(stoi(ip[0]));
        
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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */



class Solution{
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int maxGCD(Node* root){
        if(root==NULL){
            return 0;
        }
        int maxgcd = 0;
        queue<Node*>q;
        int ans = 0;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            if(node->left && node->right && maxgcd<=gcd(node->left->data,node->right->data)){
                maxgcd = gcd(node->left->data,node->right->data);
                ans = node->data;
            }
        }
        return ans;
    }
};

// class Solution{
// public:
//     int gcd(int a,int b){
//         if(b==0) return a;
//         return gcd(b,a%b);
//     }
//     void dfs(Node* root,int &maxgcd,int &node){
//         if(!root) return;
//         if(root->left && root->right){
//             int val=gcd(root->left->data,root->right->data);
//             if(val>maxgcd){
//                 maxgcd=val;
//                 node=root->data;
//             }else if(val==maxgcd){
//                 if(root->data>node){
//                     node=root->data;
//                 }
//             }
//         }
//         dfs(root->left,maxgcd,node);
//         dfs(root->right,maxgcd,node);
//     }
//     int maxGCD(Node* root){
//         if(!root) return 0;
//         int maxgcd=INT_MIN; int node=-1;
//         dfs(root,maxgcd,node);
//         if(node==-1){
//             return 0;
//         }
//         return node;
//     }
// };

  



//{ Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		Solution ob;
		cout<<ob.maxGCD(root)<<endl;
    }
    return 0;
}

// } Driver Code Ends