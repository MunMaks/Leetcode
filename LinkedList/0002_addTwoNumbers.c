/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/description/

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

void liberer(struct ListNode **head){
    if (!*head) return;
    struct ListNode *tmp = NULL;
    while (*head){
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ans = malloc(sizeof(*ans));
    if (!ans){
        fprintf(stderr, "Pas de mémoire\n");
        goto return_null;
    }

    struct ListNode* temp = ans;
    int carry = 0, sum = 0, stay = 0;
    while (l1 && l2){
        sum = l1->val + l2->val + carry;
        temp->next = malloc(sizeof(*temp->next));
        if (!temp->next){
            fprintf(stderr, "Pas de mémoire pour le suivant\n");
            goto clean_up;
        }

        temp->next->val = sum%10;
        carry = sum/10;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1) {
        sum = l1->val + carry;
        temp->next = malloc(sizeof(*temp->next));
        if (!temp->next){
            fprintf(stderr, "Pas de mémoire pour le suivant\n");
            goto clean_up;
        }
        temp->next->val = sum%10;
        carry = sum/10;
        temp = temp->next;
        l1 = l1->next;
    }

    while (l2) {
        sum = l2->val + carry;
        temp->next = malloc(sizeof(*temp->next));
        if (!temp->next){
            fprintf(stderr, "Pas de mémoire pour le suivant\n");
            goto clean_up;
        }
        temp->next->val = sum%10;
        carry = sum/10;
        temp = temp->next;
        l2 = l2->next;
    }

    if (carry) {
        temp->next = malloc(sizeof(*temp->next));
        if (!temp->next){
            fprintf(stderr, "Pas de mémoire pour le suivant\n");
            goto clean_up;
        }
        temp->next->val = carry;
        temp = temp->next;
    }
    temp->next = NULL;
    return ans->next;


clean_up:
    liberer(&ans);

return_null:
    return NULL;
}
