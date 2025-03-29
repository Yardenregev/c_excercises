#include <stdlib.h>

char *combineStrings(char *s, size_t s_len, char *t, size_t t_len)
{
    char *res = malloc((s_len+t_len+1)*sizeof(char));
    if (res == NULL)
        return NULL;
    char *ptr = res;
    size_t i = 0;
    while(s != NULL && *s != '\0')
    {
        *ptr = *s;
        ptr++;
        s++;
    }
    while (t != NULL && *t != '\0')
    {
        *ptr = *t;
        ptr++;
        t++;
    }
    *ptr = '\0';

    return res;
}
