/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Reminded me of arithmetic classes in elementary school :D
    // Initialized as 1, because I want to use it to increment
    // the least significant number without extra if-s in the 
    // second loop.
    int rememberedNumber = 1;
    // size of an array we are going to malloc. Will be greater than
    // digitsSize by 1 if incrementing will add a new digit.
    // Essentially, it will happen if the array consists only of 9-s:
    // 9999 (4) + 1 = 10000 (5)
    int mallocSize = digitsSize;
    for (int i = 0; i < digitsSize; ++i) {
        if (digits[i] != 9) {
            break;
        }
        if (i ==digitsSize - 1) {
            mallocSize++;
        }
    }
    
    // calloc will initialize everything with 0
    int* result = calloc(mallocSize, sizeof(int));
    *returnSize = mallocSize;
    
    // i belongs to digits, j - to result
    for (int i = digitsSize - 1, j = mallocSize - 1; j >= 0; --i, --j) {
        result[j] = rememberedNumber;
        if (i >= 0) {
            result[j] += digits[i];
        }
        rememberedNumber = 0;
        // We are incrementing, so it can only turn 9->10
        if (result[j] == 10) {
            result[j] = 0;
            rememberedNumber = 1;
        }
    }
    return result;
} 
