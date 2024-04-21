/*
1530. Number of Good Leaf Nodes Pairs
https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

You are given the root of a binary tree and an integer distance.
A pair of two different leaf nodes of a binary tree is said to be good
if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

Example 1:
Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3.
This is the only good pair.

Example 2:
Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2.
The pair [4,6] is not good because the length of ther shortest path between them is 4.

Example 3:
Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
*/

typedef struct TreeNode* Arbre;
void liberer_arr(int **arr){
    if (!arr){
        return;
    }
    free(*arr);
    *arr = NULL;
}


int *dfs(Arbre root, int distance, int *ansCnt, int *idx){

    if (!root->left && !root->right) {   /* une feuille */
        int *ret = malloc(sizeof *ret);
        if (!ret){
            fprintf(stderr, "Pas assez de memoire\n");
            return NULL;
        }
        ret[0] = 1;
        (*idx) = 1;
        return ret;
    }

    int lidx = 0, ridx = 0;
    int *lbuf = NULL, *rbuf = NULL;

    /* On va a gauche si c'est possible */
    if (root->left)
        lbuf = dfs(root->left, distance, ansCnt, &lidx);

    /* On va a droite si c'est possible */
    if (root->right)
        rbuf = dfs(root->right, distance, ansCnt, &ridx);

    int *ret = calloc(lidx + ridx, sizeof *ret);
    if (!ret){
        fprintf(stderr, "Pas assez de memoire\n");
        return NULL;
    }

    if (lidx && ridx){
        int cnt = 0;
        for (int i = 0; i < lidx; ++i) {
            for (int j = 0; j < ridx; ++j) {
                int dis = lbuf[i] + rbuf[j];

                if (dis <= distance) { (*ansCnt)++; }
            }
        }
    }

    /* prepare leaf distance for parent root's use */
    if (lidx) {
        for (int i = 0; i < lidx; ++i) {
            if (lbuf[i] + 1 < distance){
                ret[(*idx)++] = lbuf[i] + 1;
            }
        }
    }

    if (ridx) {
        for (int i = 0; i < ridx; ++i) {
            if (rbuf[i] + 1 < distance) {
                ret[(*idx)++] = rbuf[i] + 1;        
            }
        }
    }
    return ret;    
}


int countPairs(Arbre root, int distance){
    if (!root) return 0;
    int ansCnt = 0, idx = 0;
    int *arr = dfs(root, distance, &ansCnt, &idx);
    liberer_arr(&arr);
    return ansCnt;
}
