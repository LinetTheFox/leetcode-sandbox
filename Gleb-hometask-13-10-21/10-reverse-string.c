void reverseString(char* s, int sSize) {
    // Apparently sSize doesn't include \0
    for (int begin = 0, end = sSize - 1; begin < end; ++begin, --end) {
        s[begin] = s[begin] + s[end];
        s[end] = s[begin] - s[end];
        s[begin] = s[begin] - s[end];
    }
}
