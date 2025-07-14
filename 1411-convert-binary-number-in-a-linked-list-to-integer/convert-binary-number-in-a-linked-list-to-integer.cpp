class Solution {
public:
    ListNode* revLL(ListNode* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* last=revLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    int getDecimalValue(ListNode* head) {
        head=revLL(head);
        int res=0;
        int power=0;
        while(head!=NULL){
            if(head->val==1){
                res+=pow(2,power);
            }
            power++;
            head=head->next;
        }
        return res;
    }
};

// class Solution {
// public:
//     int binToDec(string s){
//         int dec=0;
//         int base=1;
//         int n=(int) s.length();
//         for(int i=n-1;i>=0;i--){
//             if(s[i]=='1'){
//                 dec+=base;
//             }
//             base=base*2;
//         }
//         return dec;
//     }
//     int getDecimalValue(ListNode* head) {
//         string s;
//         ListNode* curr=head;
//         while(curr!=NULL){
//             int data=curr->val;
//             char x=(data==1)? '1':'0';
//             s=s+x;
//             curr=curr->next;
//         }
//         int ans=binToDec(s);
//         return ans;
//     }
// };