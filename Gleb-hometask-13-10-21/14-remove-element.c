int removeElement(int* nums, int numsSize, int val) {
    int nextElement = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[nextElement] = nums[i];
            nextElement++;
        }
    }
    
    return  nextElement;
}
