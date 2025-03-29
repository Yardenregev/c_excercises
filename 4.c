#include <stdio.h>

void swap(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void flipArray(int *arr, size_t size)
{
    if (arr == NULL)
        return;
    int *l = arr;
    int *r = arr + size - 1;
    while(l < r)
    {
        swap(l,r);
        l++;
        r--;
    }
}
