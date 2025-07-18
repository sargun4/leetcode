#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1,ListNode* l2){
        if(l1==NULL) return l2; // If first list is empty, return second
        if(l2==NULL) return l1;
        if(l1->val<=l2->val){
            l1->next=mergeTwoSortedLists(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoSortedLists(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    //Divide & merge lists bw index start n end
    ListNode* partitionNmerge(int start,int end,vector<ListNode*>&lists){
        if(start>end) return NULL;
        if(start==end) return lists[start];
        int mid=(start+end)/2;
        //rec divide n merge both halves
        ListNode* l1=partitionNmerge(start,mid,lists);
        ListNode* l2=partitionNmerge(mid+1,end,lists);
        return mergeTwoSortedLists(l1,l2);
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;///no lists
        return partitionNmerge(0,k-1,lists);
    }
};
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if (lists.empty()) {
//             return nullptr;
//         }
//         return mergeKListsHelper(lists, 0, lists.size() - 1);
//     }
//     ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
//         if (start == end) {
//             return lists[start];
//         }
//         if (start + 1 == end) {
//             return merge(lists[start], lists[end]);
//         }
//         int mid = start + (end - start) / 2;
//         ListNode* left = mergeKListsHelper(lists, start, mid);
//         ListNode* right = mergeKListsHelper(lists, mid + 1, end);
//         return merge(left, right);
//     }
//     ListNode* merge(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* curr = dummy;
//         while (l1 && l2) {
//             if (l1->val < l2->val) {
//                 curr->next = l1;
//                 l1 = l1->next;
//             } else {
//                 curr->next = l2;
//                 l2 = l2->next;
//             }
//             curr = curr->next;
//         }
//         curr->next = l1 ? l1 : l2;   
//         return dummy->next;
//     }
// };
// ListNode *mergeKLists(vector<ListNode *> &lists) {
//     if(lists.empty()){
//         return nullptr;
//     }
//     while(lists.size() > 1){
//         lists.push_back(mergeTwoLists(lists[0], lists[1]));
//         lists.erase(lists.begin());
//         lists.erase(lists.begin());
//     }
//     return lists.front();
// }
// ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//     if(l1 == nullptr){
//         return l2;
//     }
//     if(l2 == nullptr){
//         return l1;
//     }
//     if(l1->val <= l2->val){
//         l1->next = mergeTwoLists(l1->next, l2);
//         return l1;
//     }
//     else{
//         l2->next = mergeTwoLists(l1, l2->next);
//         return l2;
//     }
// }