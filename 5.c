#include <stdlib.h>

int *findElement(int *arr,size_t size, int target)
{
    if (arr == NULL)
        return NULL;
    int *ptr = arr;
    while (ptr < arr + size)
    {
        if (*ptr == target)
            return ptr;
        ptr ++;
    }
    return NULL;
}
