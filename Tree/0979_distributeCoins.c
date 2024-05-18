/*
979. Distribute Coins in Binary Tree
https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

You are given the root of a binary tree with n nodes where each node in the tree has node.val coins.
There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another.
A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

Example 1:
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Example 2:
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
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

int dfs(Arbre root, int *count){
    int left_count = 0, right_count = 0, data = 0;
    if ( !root )
        return 0;

    left_count = dfs(root->left, count);
    right_count = dfs(root->right, count);

    if (!root->left && !root->right) {
        if (root->val == 0) {
            *count += 1;
            return -1;
        } else if (root->val == 1) {
            return 0;
        } else {
            *count += (root->val - 1);
            return (root->val - 1);
        }
    }

    data = (root->val - 1 + left_count + right_count);
    if (data < 0){
        data *= -1;
    }
    *count += data;
    return (root->val - 1 + left_count + right_count);    
}


int distributeCoins(Arbre root){
    int count = 0;
    dfs(root, &count);
    return count;
}
