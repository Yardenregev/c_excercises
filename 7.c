#include <stdlib.h>
int removeElement(int **arr, size_t size, int index) {
    if (arr == NULL || *arr == NULL || size == 0) {
        return -1;
    }
    
    if (index < 0 || index >= size) {
        return -1;
    }
    
    for (int i = index; i < size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    
    size--;
    
    int *temp = (int *)realloc(*arr, (size) * sizeof(int));
    
    if (temp == NULL && size > 0) {
        return -1;
    }
    
    *arr = temp;
    
    return 0;
}