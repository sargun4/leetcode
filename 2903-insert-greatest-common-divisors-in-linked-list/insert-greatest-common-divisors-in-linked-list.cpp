/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head; ListNode* temp=curr->next;
        while(temp!=NULL){
            ListNode* gcdNode=new ListNode(0);
            gcdNode->val=gcd(curr->val,temp->val);
            cout<<gcdNode;
            //insert gcdNode bw curr and temp nodes
            curr->next=gcdNode;
            gcdNode->next=temp;
            //move curr and temp to their next elmnt
            curr=curr->next->next;
            temp=temp->next;
        }
        return head;
    }
};