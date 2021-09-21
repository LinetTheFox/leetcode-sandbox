// TODO: naive, there must be something better
int heightChecker(int* heights, int heightsSize) {
    int *expected = malloc(sizeof(int) * heightsSize);
    int res = 0;

    // building the expected array
    for (int i = 0; i < heightsSize; ++i) {
        expected[i] = heights[i];
    }
    
    for (int i = 0; i < heightsSize; ++i) {
        for (int j = i + 1; j < heightsSize; ++j) {
            if (expected[i] > expected[j]) {
                expected[j] = expected[j] + expected[i];
                expected[i] = expected[j] - expected[i];
                expected[j] = expected[j] - expected[i];
            }
        }
    }
    
    for (int i = 0; i < heightsSize; ++i) {
        if (expected[i] != heights[i]) res++;
    }
    
    return res;
}

