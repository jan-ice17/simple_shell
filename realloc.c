#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @old_ptr: A pointer to the memory previously allocated.
 * @new_size: The new size of the allocated memory.
 * 
 * Return: A pointer to the newly allocated memory, or NULL if an error occurred.
 */
void *_realloc(void *old_ptr, size_t new_size) {
    void *new_ptr = NULL;
    size_t *old_size_ptr = NULL;
    size_t old_size = 0;
    size_t min_size = 0;
    char *old_char_ptr = NULL;
    char *new_char_ptr = NULL;
    size_t i = 0;

    if (new_size == 0) {
        free(old_ptr);
        return NULL;
    }

    if (old_ptr == NULL) {
        return malloc(new_size);
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }

    old_size_ptr = (size_t*)old_ptr - 1;
    old_size = *old_size_ptr;
    min_size = old_size < new_size ? old_size : new_size;

    old_char_ptr = (char*)old_ptr;
    new_char_ptr = (char*)new_ptr;

    for (i = 0; i < min_size; i++) {
        new_char_ptr[i] = old_char_ptr[i];
    }

    free(old_ptr);
    return new_ptr;
}