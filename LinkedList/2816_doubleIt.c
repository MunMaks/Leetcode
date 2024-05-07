/*
2816. Double a Number Represented as a Linked List
https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

Example 1:
Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189.
Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999.
Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
*/

typedef struct ListNode *LinkedList;

/*
struct ListNode * == LinkedList

typedef struct {
  int quot;
  int rem;
} div_t;
*/

/**
 * @brief Cette une fonction auxiliaire qui effectue
 * la multiplication par 2 et change toutes les variables
 * @param head Liste chainees
 * @return le quotient
*/
int go(LinkedList head){
    if (!head)
        return 0;

    int carry = go(head->next);
    div_t divmod = div(head->val * 2 + carry, 10);
    /* int next_carry = divmod.quot; */
    /* int next_val = divmod.rem; */
    head->val = divmod.rem;
    return divmod.quot;
}

/**
 * @brief Appelle la fonction auxiliaire
 * et alloue de la memoire si la valeur representee par head
 * a besoin plus d'espaces
 * @param head Liste chainees
 * @return la nouvelle tete de 'head'
*/
LinkedList doubleIt(LinkedList head){
    if (1 & go(head)) {
        LinkedList new_node = malloc(sizeof(*new_node));
        if (!new_node){
            fprintf(stderr, "Pas assez de memoire, on a perdu une cellule\n");
            return head;
        }
        new_node->val = 1;
        new_node->next = head;
        return new_node;
    }
    return head;
}
