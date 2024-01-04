//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    class Node{
        public : 
        int data;
        Node * left;
        Node * right;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
    };
    Node * insert(Node * root , int data , Node * &suc){  
        if(root==NULL) return  new Node(data);
        if(data < root->data){
            suc = root;
            root->left = insert(root->left , data , suc);
        }
        else{
            root->right = insert(root->right , data , suc);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {   
        Node * root = NULL;
        for(int i=n-1 ; i>=0 ; i--){
            Node * suc = NULL;
            root = insert(root , arr[i] , suc);
            if(suc)
                arr[i] = suc->data;
            else
                arr[i] = -1;
        }
        return arr;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends