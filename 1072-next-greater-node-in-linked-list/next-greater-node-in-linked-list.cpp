 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        vector<int> nxtgreater(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]){
                    nxtgreater[i]=arr[j];
                    break;
                }
            }
        }
        return nxtgreater;
    }
};