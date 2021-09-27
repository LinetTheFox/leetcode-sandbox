

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// I'm still looking for O(n) with no memory one, this is the best I could think of
// so far, cuz I'm dumb
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    // By constrains, numsSize >= 1.
    // Calloc will set all values to 0, we need that :)
    int *numsExisting = calloc(numsSize, sizeof(int));
    // This array will contain 1-s where we came across a number, and 0
    // if we didn't. If we come across the one where it's already 1 in
    // numsExisting, it guarantees that a number will be missing, so we
    // increment totalNumbersMissing
    int totalNumbersMissing = 0;
    // [1 ... numsSize] - actual numbers
    // [0 ... numsSize - 1] - indices
    for (int i = 0; i < numsSize; ++i) {
        if (numsExisting[nums[i] - 1] == 0) {
            numsExisting[nums[i] - 1] = 1;
        } else {
            totalNumbersMissing++;
        }
    }
    *returnSize = totalNumbersMissing;
    
    if (totalNumbersMissing == 0) {
        free(numsExisting);
        // If caller runs free on this one, nothing will happen, according to specs,
        // so this is fine
        return NULL;
    }
    
    int *result = malloc(totalNumbersMissing * sizeof(int));
    
    for (int i = 0, j = 0; i < numsSize; ++i) {
        if (numsExisting[i] == 0) {
            result[j] = i + 1;
            ++j;
        }
    }
    
    
    free(numsExisting);
    return result;
}
