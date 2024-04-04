/*
https://leetcode.com/problems/length-of-last-word/description/
58. Length of Last Word
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

static int len(const char * __restrict__ mot){
    int i = 0;
    while (*mot++) ++i;
    return i;
}

int lengthOfLastWord(char * __restrict__ s) {
    int n = len(s), j = 0;
    int i = n - 1;
    for ( ; i >= 0; --i ){
        if (j == 0 && *(s + i) == ' ')
            continue;
        if ( *(s + i) != ' ')
            ++j;
        else
            break;
    }
    return j;
}
