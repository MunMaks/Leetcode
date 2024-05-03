/*
287. Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number/description/

Given an integer array nums, return an array answer such that answer[i]
is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity?
(The output array does not count as extra space for space complexity analysis.)
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int* nums, int numsSize, int* returnSize){
    int postfix = 1, i = 1;    
    int *result = malloc(numsSize * sizeof (*result) );
    if (!result)
        return NULL; /* pas de memoire, rien a faire*/

    memset(result, 0, numsSize * (sizeof *result) );

    *result = 1;
    for ( i = 1; i < numsSize; i++) {
        result[i] = nums[i - 1] * result[i - 1]; 
    }

    for ( i = numsSize - 2; i >= 0; --i) {
        postfix *= nums[i + 1];
        result[i] *= postfix;
    }

    *returnSize = numsSize;
    return result;
}
