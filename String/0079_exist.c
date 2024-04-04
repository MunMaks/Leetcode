/*
79. Word Search
https://leetcode.com/problems/word-search/description/
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], word = "ABCCED"
Output: true


Example 2:
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], word = "SEE"
Output: true
*/

static __inline__ void free_memory(bool ** __restrict__ visited, 
                            int taille, char * __restrict__ word){
    int idx = 0;
    for (idx = 0; idx < taille; ++idx)
        free(*(visited + idx));
    free(visited);
    free(word);
}

static __inline__ int longueur(const char * __restrict__ mot){
    int i = 0;
    while (*mot++) ++i;
    return i;
}

static bool dfs_board(const char ** __restrict__ board, 
            int n_row, int n_col, int row, int col, 
            const char * __restrict__ word, bool ** __restrict__ visited){
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int i = 0;
    int new_row = 0, new_col = 0;

    if ( !*word )
        return true;

    *(*(visited + row) + col) = true;

    for (i = 0; i < 4; ++i) {
        new_row = row + *(*(dir + i));      /* dir[i][0]; */
        new_col = col + *(*(dir + i) + 1);  /* dir[i][1]; */

        if (new_row < 0 || new_col < 0 || new_row >= n_row || new_col >= n_col)
            continue;

        if ( *(*(visited + new_row) + new_col) )
            continue;

        if ( *word != *(*(board + new_row) + new_col) ) /* board[new_row][new_col] */
            continue;
        
        if (dfs_board(board, n_row, n_col, new_row, new_col, word + 1, visited))
            return true;
    }
    *(*(visited + row) + col) = false;

    return false;
}

static __inline__ char * rev_str(const char * __restrict__ s) {
    char *start = NULL, *end = NULL, aux = 0;
    for (start = s, end = s + longueur(s) - 1;  start < end;  ++start, --end){
        aux = *start;
        *start = *end;
        *end = aux;
    }
    return s;
}

bool exist(char** __restrict__ board, int boardSize, 
            int * __restrict__ boardColSize, char * __restrict__ word) {
    int letter_freq[128] = {0};
    int i = 0, j = 0, k = 0;
    const int n_row = boardSize, n_col = *boardColSize;
    const char *c;

    for (i = 0; i < n_row; ++i)
        for (j = 0; j < n_col; ++j)
            ++(letter_freq[ *(*(board + i) + j) ]); /* board[i][j] */

    for (c = word; *c; ++c) {
        --(*(letter_freq + *c));
        /* pas assez de caracteres */
        if (*(letter_freq + *c) < 0)
            return false;
    }
    
    /*
    inverser la recherche si le prefixe de la chaîne > suffixe de la chaine
    si le tableau a plusieurs caracteres de prefixe,
    nous devons revenir en arriere plusieurs fois
    pour reduire le retour en arriere,
    nous utilisons plutot le suffixe
    */
    char *_word = strdup(word);
    int prefix_len = 0, suffix_len = 0;

    prefix_len = 1;
    for (c = word + 1; *c && *(c - 1) == *c; c++, prefix_len++);

    rev_str(_word);
    suffix_len = 1;
    for (c = _word + 1; *c && *(c - 1) == *c; c++, suffix_len++);

    if (prefix_len > suffix_len)
        word = _word;

    bool **visited = malloc(n_row * sizeof (*visited));
    for (i = 0; i < n_row; ++i)
        visited[i] = calloc(n_col, sizeof *(*visited));

    for (i = 0; i < n_row; ++i) {
        for (j = 0; j < n_col; ++j) {
            if ( *(*(board + i) + j) == *word) {

                for (k = 0; k < n_row; ++k)
                    memset( *(visited + k), 0, n_col * sizeof *(*visited));

                if (dfs_board(board, n_row, n_col, i, j, word + 1, visited)){
                    free_memory(visited, n_row, _word);
                    return true;
                }
            }
        }
    }
    free_memory(visited, n_row, _word);
    return false;
}
