#include <stdlib.h>
#include <stdio.h>

void callFuncOnArrayElements(int *arr, size_t size, void (*func)(int))
{
    if (arr == NULL)
        return;
    for(int i = 0; i < size; i++)
        func(arr[i]);
}

void printInt(int a)
{
    printf("%d\r\n",a);
}

int main()
{
    int arr [] = {1,2,3,4,5};
    callFuncOnArrayElements(arr,sizeof(arr)/sizeof(int),printInt);

    return 0;
}