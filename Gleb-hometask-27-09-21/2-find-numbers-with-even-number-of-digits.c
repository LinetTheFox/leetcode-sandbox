// Checks the condition for 2, 4 or 6 digits
// TODO: i'm sure there's a better way
int condition(int num) {
    if (num > 9 && num < 100) {
        return 1;
    } else if (num > 999 && num < 10000) {
        return 1;
    } else if (num == 100000) {
        return 1;
    }
    return 0;
}

int findNumbers(int* nums, int numsSize){
    int total = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        if (condition(nums[i])) total++; 
    }

    return total;
}

