int strStr(char * haystack, char * needle) {
    
    // Edge case of an empty needle
    if (!(*needle)) return 0;

    int haystackIndex = 0; // haystackIndex that we'll return
    
    for (; *haystack; ++haystack) {
        char *needleI = needle; // inner needle iterator
        char *haystackI = haystack; // inner haystack iterator
        int equals = 1;
        
        for (; *needleI; ++needleI, ++haystackI) {
            // In case we run into the end of haystack and needle
            // hasn't finished yet, then it's not really a substring.
            // In fact, it doesn't even make sense to search further,
            // since the remaining haystack will be smaller than current
            // one which is smaller than needle. So we can calmly return
            // -1 here.
            if (*haystackI != *needleI) {
                if (!(*haystackI) && *needleI) return -1;
                equals = 0;
            }
        }
        if (equals) {
            return haystackIndex;
        } else {
            ++haystackIndex;
        }
    }
    
    return -1;
}
