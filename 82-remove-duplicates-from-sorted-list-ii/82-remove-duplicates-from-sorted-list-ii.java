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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp = null, copy = head;
        int prev = -2^32;
        while(copy != null){
            if(copy.next != null){
                if(copy.val == copy.next.val){
                    prev = copy.val;
                }
            }
            if(prev == copy.val){
                copy = copy.next;
                continue;
            }
            temp = insertFunction(temp, copy.val);
            copy = copy.next; 
        }
        return temp;
    }
    
    ListNode insertFunction(ListNode n, int value){
        ListNode tempCopy = n;
        ListNode new_node = new ListNode(value, null);
        if(n == null) return new_node;
        else {
            while(tempCopy.next != null){
                tempCopy = tempCopy.next;
            }
            tempCopy.next = new_node;
            return n;
        }
    }
}