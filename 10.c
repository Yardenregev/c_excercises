#include <stdlib.h>
typedef struct Pool{
    void *buffer;
    void *free_list;
}Pool;

Pool *InitMemoryPool(size_t sizeOfCell,size_t numberOfCells)
{
    Pool *pool = malloc(sizeof(Pool));
    if (NULL == pool)
        return NULL;
    pool->buffer = malloc(numberOfCells*sizeOfCell);
    if(NULL == pool->buffer)
    {
        free(pool);
        pool = NULL;
        return NULL;
    }
    void *ptr = pool->buffer;
    for (int i = 0; i < numberOfCells-1; i++)
    {
        *(void**)((char*)(ptr) + (i*sizeOfCell)) = (char*)(ptr) + ((i+1)*sizeOfCell);
    }
    
    *(void**)((char*)(ptr) + ((numberOfCells-1)*sizeOfCell)) = NULL;
    pool->free_list = pool->buffer;

    return pool;
}

void *Alloc(Pool *pool)
{
    if (NULL == pool || NULL == pool->free_list)
        return NULL;
    void *ptr = pool->free_list;
    pool->free_list = *(void**)(pool->free_list);
    return ptr;
}

void Free(Pool *pool, void *ptr)
{
    if (ptr == NULL)
        return;
    *(void**)ptr = pool->free_list;
    pool->free_list = ptr;
}

void Destroy(Pool *pool)
{
    if (NULL == pool)
        return;
    free(pool->buffer);
    pool->buffer = NULL;
    free(pool);
    pool = NULL;
}