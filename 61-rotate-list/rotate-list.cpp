class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        //find length of LL
        ListNode*curr=head;
        int len=1;
        while(curr->next!=NULL && ++len){
            curr=curr->next;
        }
        ///go till that node
        curr->next=head;
        k=k%len;
        k=len-k;
        while(k--){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//        if(!head)
//            return NULL;
//         int n = 1;
//         ListNode* tail = head;
//         while(tail->next){
//             n++;
//             tail = tail->next;
//         }
//         tail->next = head;
//         int size = n - k % n;
//         for(int i = 0; i < size; i++){
//             tail = tail->next;
//         }  
//         head = tail->next;
//         tail->next = NULL;
//         return head;
//     }
// };