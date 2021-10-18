void reverseChars(char* from, char* to) {
    for (; from != to && from < to; ++from, --to) {
        *from = *from + *to;
        *to = *from - *to;
        *from = *from - *to;
    }
}


char * reverseWords(char * s) {
    char *sI = s; // iterator over s
    
    // pointers that will be used for reversing
    char *begin, *end;
    
    // flag telling us that we are "scanning" a word
    int scanningWord = 0;
    
    for (;; ++sI) {
        if (*sI != ' ' && !scanningWord) {
            scanningWord = 1;
            begin = sI;
        }
        if (*sI == ' ' || *sI == '\0' && scanningWord) {
            scanningWord = 0;
            end = sI - 1;
            reverseChars(begin, end);
            if (!(*sI)) {
                break;
            }
        }
    }
    
    return s;
}
