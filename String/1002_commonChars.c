/*
1002. Find Common Characters
https://leetcode.com/problems/find-common-characters/description

Given a string array words,
return an array of all characters that show up in all strings
within the words (including duplicates).
You may return the answer in any order.

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:
- 1 <= words.length <= 100
- 1 <= words[i].length <= 100
- words[i] consists of lowercase English letters.
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **commonChars(char **words, int wordsSize, int *returnSize) {
    int frqs[wordsSize][26], cmns[26] = {0}, i = 0, j = 0;
    char *c = NULL;

    /* count common frequencies */
    for (i = 0; i < wordsSize; ++i) {
        memset(frqs[i], 0, 26 * sizeof(**frqs));
        for (c = words[i]; *c; ++c) {
            frqs[i][*c - 'a']++;
        }
        for (j = 0; j < 26; ++j) {
            if (!i) {
                cmns[j] = frqs[i][j];
                continue;
            }
            cmns[j] = (cmns[j] > frqs[i][j]) ?
                      (frqs[i][j]) :
                      (cmns[j]) ;
        }
    }

    *returnSize = 0;
    for (j = 0; j < 26; ++j) {
        *returnSize += cmns[j];
    }

    /* build the result */
    char **result = malloc(*returnSize * sizeof(*result));
    if (!result){
        fprintf(stderr, "Pas de mémoire\n");
        goto return_null;
    }

    for (i = 0, j = 0; j < 26; ++j) {
        while (cmns[j] > 0) {
            result[i] = malloc(2 * sizeof(*result[i]));

            /* libérer la mémoire allouée si l'allocation est chouée */
            if (!result[i]){
                fprintf(stderr, "Pas de mémoire, à l'intérieur\n");
                for (int idx = 0; idx < i; ++idx) { free(result[idx]); }
                goto clean_up;
            }

            *result[i] = 'a' + j;
            *(result[i++] + 1) = '\0';  /* result[i++][1] = '\0'; */
            cmns[j]--;
        }
    }

    return result;

clean_up:
    free(result);

return_null:
    return NULL;
}
