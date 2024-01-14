#include "shell.h"

/**
 * Reallocates a memory block with a new size.
 * 
 * @ptr:   Pointer to the memory block to be reallocated.
 * @size:  New size of the memory block.
 * @return Pointer to the reallocated memory block, or NULL if the allocation fails.
 */
void *_realloc(void *ptr, size_t size) {
    header_t *head;
    header_t *new_ptr;

    if (!ptr) {
        /* If pointer is NULL, be like malloc */
        new_ptr = malloc(size + sizeof(header_t));
        if (new_ptr) {
            new_ptr->size = size;
            return new_ptr + 1;
        } else {
            return NULL;
        }
    }

    head = (header_t *)ptr - 1;

    if (head->size + sizeof(header_t) >= size) {
        /* If existing block is large enough, return original pointer */
        return ptr;
    }

    /* Allocate new block with extra space for header */
    new_ptr = malloc(size + sizeof(header_t));
    if (new_ptr) {
        /* Copy contents to new block and free the old block */
        size_t copy_size = (head->size < size) ? head->size : size;
        memcpy(new_ptr + 1, ptr, copy_size);
        free(head);
        new_ptr->size = size;
        return new_ptr + 1;
    } else {
        return NULL;
    }
}