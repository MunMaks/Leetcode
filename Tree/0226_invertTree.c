/*
226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/description/

Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]
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

static void prefixe(Arbre root) {
    if (root){
        /*swap des sous arbres */
        Arbre noeud = root->left;  
        root->left = root->right;
        root->right = noeud;

        prefixe(root->left);
        prefixe(root->right);
    }
}

Arbre invertTree(Arbre root) {
    prefixe(root);
    return root;
}
