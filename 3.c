#include <stdio.h>
void printArray(int *arr,size_t size)
{
    if (arr == NULL)
        return;
    int *ptr = arr;
    while(ptr < arr + size)
    {
        printf("%d,",*ptr);
        ptr++;
    }
}
