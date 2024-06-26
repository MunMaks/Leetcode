/*
112. Path Sum
https://leetcode.com/problems/path-sum/description/

Given the root of a binary tree and an integer targetSum,
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

*/

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root) { return false; }  /* si la racine est NULL, rien a faire*/
    
    targetSum -= root->val;  /* on soustrait le noeud actuel */

    if (!root->left && !root->right) { return !targetSum; } /* on a trouve une feuille */

    /* parcourir l'arbre de maniere recursive */
    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
}
