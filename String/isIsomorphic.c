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
