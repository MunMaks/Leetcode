/*
543. Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

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

int dfs(Arbre root, int *result){
    if (!root) return 0;

    int left = dfs(root->left, result);
    int right = dfs(root->right, result);

    *result = ( *result > (left + right) ) ?
                (*result) : 
                (left + right);

    return (left > right) ? (left + 1) : (right + 1);
}

int diameterOfBinaryTree(Arbre root) {
    int result = 0;
    dfs(root, &result);
    return result;
}
