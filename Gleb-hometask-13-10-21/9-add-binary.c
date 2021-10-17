char addCharsAsBinaryDigits(char a, char b, int* overflowed) {
    // 48 is ASCII code for '0';
    // 50 - for '2'
    // Lots of parentheses, cuz I dunno the priority of casting,
    // so just a precaution
    int sum = ((int)a) - 48;
    sum += (((int)b) - 48);
    if (!(*overflowed)) {
        if (sum > 1) {
            *overflowed = 1;
        } else {
            *overflowed = 0;
        }   
    }
    sum = (sum % 2) + 48;
    return (char)sum;
}

char * addBinary(char * a, char * b){
    int remembered = 0;
    
    // String indices
    int aI = 0, bI = 0;
    // Getting the last index of each string
    for (; a[aI]; ++aI) {}
    for (; b[bI]; ++bI) {}
    
    int maxIndex = aI > bI ? aI : bI;
    
    // allocating the result string of size max(i, j) + 1 - to
    // store space for the increased size
    char *res = malloc((maxIndex + 2) * sizeof(char));
    res[maxIndex + 1] = '\0';
    
    // In loops we counted \0, but we don't need it in the operation itself
    --aI;
    --bI;
    
    for (int i = maxIndex; i >= 0; --i) {
        if (remembered) {
            res[i] = '1';
            remembered = 0;
        } else {
            res[i] = '0';
        }
        if (aI >= 0) {
            res[i] = addCharsAsBinaryDigits(res[i], a[aI], &remembered);
            --aI;
        }
        if (bI >= 0) {
            res[i] = addCharsAsBinaryDigits(res[i], b[bI], &remembered);
            --bI;
        }
        
    }
    // Without more complex stuff in above, we won't know if we need the
    // extra space for addition or not (except, maybe doing custom atoi and itoa).
    // So in case we end up with leading 0, we reallocate the new array of smaller
    // size (math average of this happening - 0.5), so further it can be free-d.
    // We can use a hack to just increment res pointer, but in this case it will
    // be un-free-able, which is kinda bad since it's technically a memory leak :).
    if (res[0] == '0') {
        char *resS = malloc((maxIndex + 1) * sizeof(char));
        for (int i = 0; i <= maxIndex; ++i) {
            // Includes '\0'
            resS[i] = res[i + 1];
        }
        return resS;
        free(res);
    }
    return res;
}
