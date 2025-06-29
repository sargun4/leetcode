//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

int sumLeaf(Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumLeaf(root)<<endl;
  }
  return 0;
}

// } Driver Code Ends


// function should return the sum of all the 
// leaf nodes of the binary tree 
bool isLeaf(Node* root){
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}
int sumLeaf(Node* root){
    int sum=0;
    queue<Node*> q;
    q.push(root);
    if(root==NULL) return sum;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* node=q.front();
            q.pop();
            if(isLeaf(node)){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return sum;
}