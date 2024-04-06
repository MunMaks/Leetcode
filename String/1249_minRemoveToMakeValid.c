/*
1249. Minimum Remove to Make Valid Parentheses
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) 
so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:
- It is the empty string, contains only lowercase characters, or
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.
 
Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
*/

char* minRemoveToMakeValid(char* s) {
    int length = strlen(s);
    int numLeftParentheses = 0;
    char* pS = s;
    for (int i = length; i > 0; --i, ++pS){
        char c = *pS;
        if (c == '(')
            ++numLeftParentheses;
        else if (c == ')') {
            if (--numLeftParentheses < 0){
                *pS = ' ';
                numLeftParentheses = 0;
            }
        }
    }

    if (numLeftParentheses > 0) {
        pS = s + length - 1;
        for (int i = length; i > 0; --i, --pS){
            if (*pS == '(') {
                *pS = ' ';
                if (--numLeftParentheses == 0)
                    break;
            }
        }
    }
    int skipped = 0;
    pS = s;
    for (int i = length; i > 0; --i, ++pS){
        if (*pS == ' ')
            ++skipped;
        else 
            *(pS - skipped) = *pS;
    }
    s[length - skipped] = '\0';
    return s;
}
