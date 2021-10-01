// I kinda did remove the if from top, but I effectively moved
// it to return instead of beginning :^)
// Ik it's probably not what was meant, but dunno how else we
// can do it without skipping the first element
int removeDuplicates(int* nums, int numsSize) {
    int next_pos = 1;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != nums[next_pos - 1]) {
            nums[next_pos++] = nums[i];
        }
    }
    return numsSize ? next_pos : 0;
}

