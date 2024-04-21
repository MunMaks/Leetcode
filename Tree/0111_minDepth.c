/*
111. Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
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

int minDepth(Arbre root){
    if (!root) return 0;    /* la racine est NULL */
    if (!root->left && !root->right) return 1;    /* une feuille */

    int left = 0xFFFFF, right = 0xFFFFF;    /* un grand nombre 10^6 */

    if (root->left) { left = minDepth(root->left); }       /* si a gauche existe */
    if (root->right) { right = minDepth(root->right); }    /* si a droite existe */

    return (left > right) ? (right + 1) : (left + 1);      /* la comparaison */
}
