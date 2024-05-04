/*
881. Boats to Save People
https://leetcode.com/problems/boats-to-save-people/description/

You are given an array people where people[i] is the weight of the ith person,
and an infinite number of boats where each boat can carry a maximum weight of limit.
Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Example 2:
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Example 3:
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/

/**
 * @brief fonction de comparaison pour trier
*/
int comparer(const void *left, const void *right){
    return *(int *)left - *(int *)right;
}

/**
 * @brief Effectue le trie du tableaux et renvoie le nombre de bateaux
 * en utilisant l'algorithme a deux pointeurs
 * @return le nombre minimum de bateaux
*/
int numRescueBoats(int* people, int peopleSize, int limit) {
    int compteur = 0;
    int left = 0, right = peopleSize - 1;

    /* trier */
    qsort(people, peopleSize, sizeof(*people), &comparer);

    while (left <= right){
        /* On ne peut avoir que 2 personnes par bateau */
        if (people[left] + people[right] <= limit){ 
            ++left;
        }
        ++compteur;     /* quantite */
        --right;
    }

    return compteur;
}
