/*
78. Subsets

Given an integer array nums of unique elements,
return all possible subsets (the power set).

The solution set must not contain duplicate subsets.
Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

void backtrack(int* nums, int numsSize, int** res, int* returnSize,
               int** returnColumnSizes, int* tmp, int tarSize, int cidx, int start) {
    if (cidx == tarSize) {
        (*returnColumnSizes)[(*returnSize)] = cidx;
        res[(*returnSize)] = malloc(cidx * sizeof(*(res[(*returnSize)])) );
        if (!res[(*returnSize)]){
            fprintf(stderr, "Pas assez de mémoire, réessayez!\n");
            return;     /* On peut améliorer la géstion des erreurs pour être sûr */
        }
        if (tarSize){
            memcpy(res[(*returnSize)], tmp, cidx * sizeof(tarSize));
        }
        (*returnSize)++;
    } else {
        for (int i = start; i < numsSize; i++) {
            tmp[cidx] = nums[i];
            backtrack(nums, numsSize, res, returnSize,
                      returnColumnSizes, tmp, tarSize, cidx + 1, i + 1);
        }
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = pow(2, numsSize), i = 0;
    *returnSize = 0;
    *returnColumnSizes = malloc(size * sizeof(*returnColumnSizes));
    if (!*returnColumnSizes){
        fprintf(stderr, "Problème de mémoire 1\n");
        goto return_null;
    }
    int** res = malloc(size * sizeof(*res));
    if (!res){
        fprintf(stderr, "Problème de mémoire 2\n");
        goto clean_up;
    }
    int* tmp = malloc(numsSize * sizeof(*tmp));
    if (!tmp){
        fprintf(stderr, "Problème de mémoire 3\n");
        goto clean_all;
    }
    for (i = 0; i <= numsSize; ++i) {
        backtrack(nums, numsSize, res, returnSize, returnColumnSizes, tmp, i, 0, 0);
    }
    free(tmp);
    return res;


clean_all:
    free(res);

clean_up:
    free(*returnColumnSizes);

return_null:
    return NULL;
}
