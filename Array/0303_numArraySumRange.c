/*
303. Range Sum Query - Immutable
https://leetcode.com/problems/range-sum-query-immutable/description/

Given an integer array nums, handle multiple queries of the following type:
1) Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the NumArray class:
- NumArray(int[] nums) Initializes the object with the integer array nums.
- int sumRange(int left, int right)
  Returns the sum of the elements of nums between indices left and right inclusive
  (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/



typedef struct {
    int numsSize;
    int *arr;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *array = malloc(sizeof *array);
    if (!array){
        fprintf(stderr, "Pas de memoire\n");
        return NULL;
    }

    array->arr = malloc(numsSize * sizeof *array->arr);
    if (!array->arr){
        fprintf(stderr, "Pas de memoire pour array\n");
        free(array);
        return NULL;
    }
    array->numsSize = numsSize;
    array->arr[0] = nums[0];
    for (int i = 1; i < numsSize; ++i)
        array->arr[i] = array->arr[i - 1] + nums[i];

  return array;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if (!obj) return -1;
    return (left > 0) ?
        (obj->arr[right] - obj->arr[left - 1]) :
        (obj->arr[right]);
}

void numArrayFree(NumArray* obj) {
    if (obj){
        free(obj->arr);
        free(obj);
    }
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
