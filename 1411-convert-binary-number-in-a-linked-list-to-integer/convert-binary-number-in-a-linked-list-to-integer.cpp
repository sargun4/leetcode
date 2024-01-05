class Solution {
public:
    int binToDec(string s){
        int dec=0;
        int base=1;
        int n=(int) s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                dec+=base;
            }
            base=base*2;
        }
        return dec;
    }
    int getDecimalValue(ListNode* head) {
        string s;
        ListNode* curr=head;
        while(curr!=NULL){
            int data=curr->val;
            char x=(data==1)? '1':'0';
            s=s+x;
            curr=curr->next;
        }
        int ans=binToDec(s);
        return ans;
    }
};