/*
4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/description/

Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log(m + n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/


/**
 * @brief Effectue la recherche de la mediane entre deux tableaux triees
 * @param nums1 - premier tableau triee
 * @param nums1Size - la taille de nums1
 * @param nums1 - deuxieme tableau triee
 * @param nums2Size - la taille de nums2
 * @return (double) mediane
 */
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    double first = 0, second = 0;

    while (i + j <= (nums1Size + nums2Size) / 2 ){
        /* on suppose que a est toujours plus petit que b */
        first = second;

        /* si les deux indices sont valides */
        if (i < nums1Size && j < nums2Size) {
            if ( nums1[i] < nums2[j] ){ /* la comparaison simple */
                second = nums1[i];
                ++i;
            } else {
                second = nums2[j];
                ++j;
            }
        } else if (j < nums2Size){  /* si j est un indice valide */
            second = nums2[j];
            ++j;
        } else {    /* sinon, i est un indice valide */
            second = nums1[i];
            ++i;
        }
    }
    /* le calcul de mediane, en fonction de la taille totale */
    return  (nums1Size + nums2Size) % 2 ?
            (second) :              /* si la taille est impair (odd) */
            (first + second) / 2;   /* si la taille est pair   (even)*/
}
