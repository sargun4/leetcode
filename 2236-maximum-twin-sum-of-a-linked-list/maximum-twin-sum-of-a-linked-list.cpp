
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* midnext=slow->next;
        slow->next=NULL;
        midnext=rev(midnext);

        vector<int> arr;
        while(midnext!=NULL){
            arr.push_back(midnext->val+head->val);
            head=head->next;
            midnext=midnext->next;
        }
        int maxsum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxsum){
                maxsum=arr[i];
            }
        }
        return maxsum;
    }
};