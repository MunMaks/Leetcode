/*
409. Longest Palindrome
https://leetcode.com/problems/longest-palindrome/description/

Given a string s which consists of lowercase or uppercase letters,
return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/


/*
  s'il est compliqué à lire, rappelez-vous que en C
  arr[i] == *(arr + i), alors ça veut dire qu'on peut écrire
  i[arr] ...
  Donc, perso je préfère `*(arr + i)`
*/
int longestPalindrome(char *s) {
    int count = 0, i = 0;
    uint16_t arr[128] = {0};
    uint8_t mid = 0;
    while (*s){
        if ( !*(arr + (*s)) ){  /* la prémière fois qu'on voit ce caractère */
            *(arr + (*s)) = 1;
        } else {                /* déjà vu */
            ++(*(arr + (*s)));
        }
        ++s;  /* itération */
    }

    for (i = 0; i < 128; ++i){
        if ( !(*(arr + i) % 2) ){  /* des nombres pairs */
            count += *(arr + i);
        } else if ( !mid ) {       /* une fois un nombre impaire */
            count += *(arr + i);
            ++mid;
        } else {
            count += (*(arr + i) - 1);  /* des nombres impairs */
        }
    }
    return count;
}

