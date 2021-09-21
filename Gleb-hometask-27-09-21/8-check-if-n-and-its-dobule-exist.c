// wtf, C doesn't have bool!
// custom enum?
// 
// P.S. oh, I see, #include <stdbool.h> from C99
bool checkIfExist(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        for (int j = i + 1; j < arrSize; ++j) {
            if ((arr[i] == arr[j] * 2) || (arr[i] * 2 == arr[j])) {
                return true;
            }
        }
    }
    return false;
}

