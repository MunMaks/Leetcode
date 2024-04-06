/*
1544. Make The String Great
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where: 0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them.
You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
Notice that an empty string is also good.

Example 1:
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".

Example 2:
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

Example 3:
Input: s = "s"
Output: "s"
*/

/*
43.  if (top >= 0 && (s[i] ^ s[top]) == 32)
Cette condition verifie si le caractere actuel s[i] est egal au caractere en haut de la "pile" (a l'index top), en ignorant la casse.
Elle le fait en effectuant une operation XOR bitwise (^) entre les valeurs ASCII des deux caracteres.
Si le resultat de l'operation XOR est 32, cela signifie que les caracteres sont la meme lettre
mais dans des cas differents (par exemple, 'a' et 'A' ou 'z' et 'Z').
Si cette condition est vraie, cela signifie que nous avons trouve une paire de caracteres a supprimer.
*/

char* makeGood(char* s) {
    int n = strlen(s);
    int top = -1;
    for (int i = 0; i < n; ++i) {
        if (top >= 0 && (s[i] ^ s[top]) == 32) {
            --top;
        } else {
            ++top;
            s[top] = s[i];
        }
    }
    s[++top] = '\0';
    return s;
}
