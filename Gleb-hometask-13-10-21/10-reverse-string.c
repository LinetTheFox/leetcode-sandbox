void reverseString(char* s, int sSize) {
    char buffer = 0;
    // Apparently sSize doesn't include \0
    for (int begin = 0, end = sSize - 1; begin < end; ++begin, --end) {
        buffer = s[end];
        s[end] = s[begin];
        s[begin] = buffer;
    }
}
