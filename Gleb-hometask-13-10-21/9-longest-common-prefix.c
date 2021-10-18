char * longestCommonPrefix(char ** strs, int strsSize) {
    int prefixSize = 0;
    char* res;
    for (;; ++prefixSize) {
        if (strs[0][prefixSize] == '\0') break;
        char cmp = strs[0][prefixSize];
        for (int j = 1; j < strsSize; ++j) {
            // If one string has finished, provided, we reached it,
            // the prefix size is already set
            if (strs[j][prefixSize] != cmp || !strs[j][prefixSize]) {
                // For the first time unironically using goto
                goto endLoops;
            }
        }
    }
    
    endLoops:
    
    res = malloc((prefixSize + 1) * sizeof(char));
    res[prefixSize] = '\0';
    for (int i = 0; i < prefixSize; ++i) {
        res[i] = strs[0][i];
    }
    return res;
}
