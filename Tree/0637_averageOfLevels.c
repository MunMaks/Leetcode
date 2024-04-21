/*
637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
Answers within 10-5 of the actual answer will be accepted.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Example 2:
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
*/

typedef struct TreeNode* Arbre;

static void liberer_memoire(long long ***table, int dep){
    if (!table){ return; }

    for (int i = 0; i < dep; ++i) free((*table)[i]);
    free(*table);
    *table = NULL;
}

static int hauteur(Arbre root){
    if ( !root )
        return 0;
    int left = hauteur(root->left);
    int right = hauteur(root->right);
    return (left > right) ? (left + 1) : (right + 1);
}


static void BFS(Arbre root, int depth, long long** table){
    if (!root) return;
    table[depth][0] += 1;
    table[depth][1] += root->val;

    if (root->left) { BFS(root->left, depth + 1, table); }
    if (root->right) { BFS(root->right, depth + 1, table); }
}


double* averageOfLevels(Arbre root, int* returnSize){
    int i = 0;
    int dep = hauteur(root);
    long long** table = malloc(dep * sizeof(*table));
    if (!table){
        fprintf(stderr, "Probleme d'allocation\n");
        return NULL;
    }

    for (i = 0; i < dep; ++i){
        table[i] = calloc(2, sizeof(*table[i]));
        if (!table[i]){
            liberer_memoire(&table, i);
            return NULL;
        }
    }

    BFS(root, 0 , table);    
    double* ans = malloc(dep * sizeof(*ans));
    if (!ans) {
        fprintf(stderr, "Pas assez de memoire\n");
        liberer_memoire(&table, dep);
        return NULL;
    }

    for (i = 0; i < dep; ++i){
        if (!table[i][0]){
            ans[i] = 0;
        } else {
            ans[i] = (double)table[i][1] / table[i][0];
        }
    }
    *returnSize = dep;
    
    liberer_memoire(&table, dep);
    return ans;
}

