int findNumbers(int* nums, int numsSize) {
    int total = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        // haven't had math classes in a while, forgot
        // there's such thing as a decimal logarithm :D
        int len = log10(nums[i]);
        if ( len % 2 == 1 ) total++; 
    }

    return total;
}
