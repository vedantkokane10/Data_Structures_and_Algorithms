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
First find out the length and then middle node by using slow and fast pointers.
Also maintain temp node which will point to previous node of slow pointer
-> Slow pointer will be the middle node, if length is odd
-> Slow pointer's next node will be the middle node, if length is even
If length is even simply assign slow next.next to to slow's next.
If length is odd simply assign slow's next to temp's next.
*/

ListNode* deleteMiddle(ListNode* head) {
    int length = 0;
    ListNode* temp = head;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }

    if(length == 1){
        return NULL;
    }
    
    ListNode* fast = head;
    ListNode* slow = head;
    temp = head;

    while(fast->next != NULL && fast->next->next != NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }   

    if(length % 2 == 0){
        if(slow->next->next != NULL){
            slow->next = slow->next->next;
        }
        else{
            slow->next = NULL;
        }
    }
    else{
        if(slow->next != NULL){
            temp->next = slow->next;
        }
        else{
            temp->next = NULL;
        }
    }
    return head;
}
