/* Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.
true == 1
false == 0

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
*/

static int longueur(const char * __restrict__ mot){
    int count = 0;
    while(*mot++) ++count;
    return count;
}


int isIsomorphic(const char * __restrict__ s, const char * __restrict__ t) {
    int s_map[256] = {0};
    int t_map[256] = {0};
    int len = longueur(s), i = 0;
    for ( i = 0; i < len; ++i ){
        if ( s_map[s[i]] != t_map[t[i]] )
            return 0;

        s_map[s[i]] = i + 1;
        t_map[t[i]] = i + 1;
    }
    return 1;
}
