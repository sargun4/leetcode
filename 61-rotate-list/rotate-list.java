class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode temp = new ListNode();
        temp = head;
        if(head==null || head.next==null || k==0) return head;
        int ctr = 1;
        while(temp.next!=null){
            temp = temp.next;
            ctr++;
        }
        temp.next = head;
        k = k%ctr;
        k = ctr-k;
        while((k--) >0){
            temp = temp.next;
        }
        head = temp.next;
        temp.next = null;
        return head;
    }
}
// public static ListNode rotateRight(ListNode head, int k) {
// 	if(head==null)
//         return null;
// 	int size = 1; // since we are already at head node
// 	ListNode fast=head;
// 	ListNode slow = head;
	
// 	while(fast.next!=null){
// 	    size++;
// 	    fast = fast.next;
// 	}
	
// 	for(int i=size-k%size;i>1;i--) // i>1 because we need to put slow.next at the start.
// 		slow = slow.next;
	
//     // No dummy variable.
// 	fast.next = head;
// 	head = slow.next;
// 	slow.next = null;
	
// 	return head;
// }

// // class Solution {
// //     public ListNode rotateRight(ListNode head, int k) {
// //         if( k == 0 || head ==null || head.next == null) return head;

// //         int len=1;
// //         ListNode cur=head;
// //         //ctr and travel to the last node;
// //         while(cur.next != null){
// //             len++;
// //             cur=cur.next;
// //         }
// //         //when k=len we get the same linked list
// //         k = len - (k%len);
// //         //make a loop by attaching last to first
// //         cur.next = head;

// //         while(k > 0){
// //             cur=cur.next;
// //             k--;
// //         } 
// //         //get the head and break the link
// //         head = cur.next;
// //         cur.next = null;

// //         return head;

// //     }
// // }

