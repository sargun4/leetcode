class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<=l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
        return NULL;
    }
};
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* head=new ListNode(0);
//         ListNode* curr=head;
//         while(l1!=NULL && l2!=NULL){
//             if(l1->val<=l2->val){
//                 curr->next=l1;
//                 l1=l1->next;
//             }else{
//                 curr->next=l2;
//                 l2=l2->next;
//             }
//             curr=curr->next;
//         }
//         if(l1!=NULL) curr->next=l1;
//         else curr->next=l2;
//         return head->next;
//     }
// };
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         //iter
//         if(l1==NULL) return l2;
//         if(l2==NULL) return l1;
//         if(l1->val>l2->val){
//             // ListNode*temp=l1;
//             // l1=l2;
//             // l2=temp;
//             std::swap(l1,l2);
//         }
//         ListNode*res=l1;
//         while(l1!=NULL && l2!=NULL){
//             ListNode*temp=NULL;
//             while(l1!=NULL && l1->val <= l2->val){
//                 temp=l1;
//                 l1=l1->next;
//             }
//             temp->next=l2;
//             std::swap(l1,l2);
//         }
//         return res;
//     }
// };