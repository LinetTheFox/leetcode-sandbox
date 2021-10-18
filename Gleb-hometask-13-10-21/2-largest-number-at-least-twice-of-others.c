// We will only need the top 2 numbers in array.
// If first > second * 2, then first is larger than anything else doubled
// Else, we already fail the condition, so we return -1
int dominantIndex(int* nums, int numsSize) {
    int firstI = -1, secondI = -1;    
    for (int i = 0; i < numsSize; ++i) {
        // If and else-if ususally happen only when we are adding first two numbers
        if (firstI == -1) {
            firstI = i;
            continue;
        } else {
            if (nums[i] > nums[firstI]) {
                secondI = firstI;
                firstI = i;
            } else if (secondI == -1 || nums[i] > nums[secondI]) {
                secondI = i;
                
            }
        }
    }
    
    // Edge cases to prevent further getting of nums[-1]
    if (firstI == -1) return -1;
    if (secondI == -1) return 0;
    
    if (nums[firstI] >= nums[secondI] * 2) {
        return firstI;
    } else {
        return -1;
    }
}
