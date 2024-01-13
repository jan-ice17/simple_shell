#include "shell.h"

/**
 * Reallocates a memory block with a new size.
 * 
 * @ptr:   Pointer to the memory block to be reallocated.
 * @size:  New size of the memory block.
 * @return Pointer to the reallocated memory block, or NULL if the allocation fails.
 */
void *_realloc(void *ptr, size_t size) {
    header_t *head = (header_t *)ptr - 1;
    size_t i;
    void *new_ptr = malloc(size);

    
    if (!ptr || !size) {
        /* If pointer is NULL or size is zero, be like malloc */
        return malloc(size);
    }

    if (head->size >= size) {
        /* If existing block is large enough, return original pointer */
        return ptr;
    }

    if (new_ptr) {
        /* Copy contents to new block and free the old block */
        size_t copy_size = (head->size < size) ? head->size : size;
        for (i = 0; i < copy_size; i++) {
            ((char *)new_ptr)[i] = ((char *)ptr)[i];
        }
        free(ptr);
    }

    return new_ptr;
}