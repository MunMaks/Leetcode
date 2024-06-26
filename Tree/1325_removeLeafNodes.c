/*
1325. Delete Leaves With a Given Value
https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target,
it should also be deleted (you need to continue doing that until you cannot).

Example 1:
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).

Example 2:
Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]

Example 3:
Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode *Arbre;

static inline int is_leaf(Arbre root){
    if (!root) return 0;
    return (!root->left && !root->right);
}


Arbre dfs(Arbre root, int target){
    if (!root) return NULL;
    root->left = dfs(root->left, target);
    root->right = dfs(root->right, target);

    if (root->val == target && (is_leaf(root))){
        free(root);
        return NULL;
    }
    return root;
}


Arbre removeLeafNodes(Arbre root, int target) {
    root = dfs(root, target);
    return root;
}
