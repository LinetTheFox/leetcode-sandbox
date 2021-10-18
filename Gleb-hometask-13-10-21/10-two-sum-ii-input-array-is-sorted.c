/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Feels like there's a better solution, just I'm dumb to come up with one
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int *res = malloc(2 * sizeof(int));
    
    for (int i = 0; i < numbersSize; ++i) {
        // The second condition limits further traversion through the array. We know array
        // is sorted, so if we run into an element that ends up in sum larger than target,
        // we skip the rest.
        for (int j = i + 1; j < numbersSize && numbers[i] + numbers[j] <= target; ++j) {
            if (numbers[i] + numbers[j] == target) {
                res[0] = i + 1;
                res[1] = j + 1;
                return res;
            }
        }
    }
    
    return res;
}
