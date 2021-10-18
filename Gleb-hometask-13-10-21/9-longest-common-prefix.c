char * longestCommonPrefix(char ** strs, int strsSize) {
    int prefixSize = 0;
    char* res;
    for (;; ++prefixSize) {
        // If we ran into the end of a string, no need to check further
        if (strs[0][prefixSize] == '\0') break;
        for (int j = 1; j < strsSize; ++j) {
            // Same here, but also as soon as we found different symbol in any string
            if (strs[j][prefixSize] != strs[j - 1][prefixSize] || !strs[j][prefixSize]) {
                // For the first time unironically using goto
                goto endLoops;
            }
        }
    }
    
    endLoops:
    
    // Creating the result string
    res = malloc((prefixSize + 1) * sizeof(char));
    res[prefixSize] = '\0';
    for (int i = 0; i < prefixSize; ++i) {
        res[i] = strs[0][i];
    }
    return res;
}
