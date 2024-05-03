/*
287. Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number/description/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
 
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
*/

/**
 * @brief la recherche d'un doublon
 * @return renvoie le doublon
*/
int findDuplicate(int* nums, int numsSize) {
    /* Initialize the pointers */
    int i = nums[0], j = nums[0];

    /* Move the pointers until they meet */
    do {
        i = nums[i];
        j = nums[nums[j]];
    } while (i != j);

    /* Find the duplicate number */
    i = nums[0];
    while (i != j) {
        i = nums[i];
        j = nums[j];
    }

    return i;
}
