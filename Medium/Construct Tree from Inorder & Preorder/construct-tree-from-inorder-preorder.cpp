//{ Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


class Solution{
    public:
    int preIdx=0;
    Node* constr(int in[],int pre[],int is,int ie){
        if (is > ie) 
            return NULL;
        Node *root = new Node(pre[preIdx]);
        preIdx++;
        int inIdx=0;
        for(int i=is;i<=ie;i++){
            if(in[i]==root->data){
                inIdx=i;
                break;
            }
        }
        root->left = constr(in,pre,is,inIdx-1);
        root->right = constr(in,pre,inIdx+1,ie);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n){
        return constr(in,pre,0,n-1);
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends