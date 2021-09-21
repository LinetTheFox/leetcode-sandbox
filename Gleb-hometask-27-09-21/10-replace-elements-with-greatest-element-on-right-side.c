/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int currentLargest = -1;
    
    *returnSize = arrSize;
    
    int *result = malloc(arrSize * sizeof(int));
    
    for (int i = arrSize - 1; i >= 0; --i) {
        result[i] = currentLargest;
        if (arr[i] > currentLargest) currentLargest = arr[i];
    }
    
    return result;
}

