/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        
        ListNode stablePointer = head;
        ListNode unstablePointer = head;
        
        while(unstablePointer != null && unstablePointer.next != null){
            stablePointer = stablePointer.next;
            unstablePointer = unstablePointer.next.next;
        }
        
        stablePointer = reverse(stablePointer);
        
        unstablePointer = head;
        
        while(stablePointer != null){
            if(stablePointer.val != unstablePointer.val){
                return false;
            }
            stablePointer = stablePointer.next;
            unstablePointer = unstablePointer.next;
        }
        return true;
    }
    
    public ListNode reverse(ListNode head){
        
        ListNode previousNode = null;
        
        while(head != null){
            ListNode next = head.next;
            head.next = previousNode;
            previousNode = head;
            head = next;
        }
        return previousNode;
    }
}