/*
572. Subtree of Another Tree
https://leetcode.com/problems/subtree-of-another-tree/description/
Given the roots of two binary trees root and subRoot,
return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants.
The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode* Arbre;

/*deja fait: https://github.com/MunMaks/Leetcode/blob/main/Tree/0100_isSameTree.c */
bool isSameTree(Arbre p, Arbre q) {
    if (!p && !q) { return true; }  /* les arbre sont deux NULL */
    else if (!p || !q) { return false; }    /* l'un d'entre n'est pas NULL */

    return (isSameTree(p->left, q->left) &&         /* la comparaison a gauche */
            isSameTree(p->right, q->right)) &&      /* la comparaison a droite */
            (p->val == q->val) ;                    /* la comparaison des valeurs */
}


bool isSubtree(Arbre root, Arbre subRoot) {
    if (!subRoot) { return true; }  /* rien a faire */
    if (!root) { return false; }    /* si la racine est NULL */
    if (isSameTree(root, subRoot)) { return true; }  /* si on a trouve cette sous-arbre */

    return isSubtree(root->left, subRoot) ||  /* a gauche */
           isSubtree(root->right, subRoot);   /* a droite */
}
