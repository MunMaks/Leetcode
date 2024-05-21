/*
203. Remove Linked List Elements
https://leetcode.com/problems/remove-linked-list-elements/description/

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    if (!head) {
        goto return_null;
    }
    struct ListNode* result = malloc(sizeof *result);
    if (!result) {
        goto return_null;
    }

    result->val = 0;
    result->next = head;
    struct ListNode *curr = result;

    while (curr->next) {
        if (curr->next->val == val){
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    curr = result->next;
    free(result);
    return curr;

return_null:
    return NULL;

}
