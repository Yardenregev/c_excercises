#include <stdlib.h>
void doubleValue(int *num)
{
    if(num == NULL)
    {
        return;
    }
    *num = *num * 2;
}
