/*
2095. Delete the Middle Node of a Linked List

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing,
where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

Example 1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 

Example - 2
Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
*/

/*
use slow and fast pointer approach to find middle element and maintain prev which will act as previous to slow
at last simply do prev->next = slow->next

*/

ListNode* deleteMiddle(ListNode* head) {
    if(head->next == NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if(slow->next != NULL){
        prev->next = slow->next;
    }
    else{
        prev->next = NULL;
    }
    return head;
}
