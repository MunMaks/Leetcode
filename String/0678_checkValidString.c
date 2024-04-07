/*
678. Valid Parenthesis String
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:
- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true
*/

bool checkValidString(char* s) {
    int leftPlus = 0;
    int leftMinus = 0;
    int i = 0;
    /*
    s[i] == *(s + i)
    if (*(s + i)) == if (*(s + i) != '\0')
    */
    for ( i = 0; *(s + i); ++i) {
        if (*(s + i) == '(') {
            ++leftPlus;             
            ++leftMinus;          
        }
        else if (*(s + i) == ')') {
            --leftPlus;           
            --leftMinus;         
        }
        else {
            ++leftPlus;     /* Etoile comme des parentheses ouvertes*/
            --leftMinus;    /* Etoile comme des  parentheses fermees*/
        }

        if (leftPlus < 0) { return false; }   /* s'il y a plus de paratheses fermees (avec des etoiles): return false */
        if (leftMinus < 0) { leftMinus = 0; } /* su des parentheses ouvertes sont negatives, avec des etoiles, alors redefinir a 0 */
    }

    return !leftMinus; /* Si tout est OK, return true */
}
