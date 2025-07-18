//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/
// sorted doubly linked list 
class Solution{
public:
    Node* findtail(Node* head){
        Node* tail=head;
        while(tail->next!=NULL) tail=tail->next;
        return tail;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node*head, int target){
        vector<pair<int, int>> ans;
        if(head==NULL) return ans;
        Node* left=head; 
        Node* right=findtail(head);
        while(left->data<right->data){
            if(left->data+right->data==target){//bin search
                ans.push_back({left->data, right->data});
                left=left->next;
                right=right->prev;
            }else if(left->data+right->data>target){//move right ptr towards left to get lesser val
                right=right->prev;
            }else{//move left ptr towards right to get highr val
                left=left->next;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends