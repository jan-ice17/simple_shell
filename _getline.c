#include "shell.h"

/**
 * Custom getline function
 * @lineptr: Pointer to the buffer containing the read line
 * @n: Pointer to the size of the buffer
 * @fd: File descriptor to read from
 * 
 * @return Number of characters read, or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, int fd) {
    static char jantee_buf[BUFFER_SIZE];
    static char *buff_ptr;
    static int c_left = 0;
    size_t i = 0;
    char c;
    char *newPtr;

    if (lineptr == NULL || n == NULL) {
        return -1; /* Invalid arguments */
    }

    /* Initialize buffer and size if not provided */
    if (*lineptr == NULL || *n == 0) {
        *n = 128;  /* Initial buffer size */
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1;  /* Memory allocation failure */
        }
    }

    while (1) {
        /* If no characters left in buffer, read more */
        if (c_left <= 0) {
            c_left = read(fd, jantee_buf, BUFFER_SIZE);
            if (c_left <= 0) {
                /* End of file or error */
                break;
            }
            buff_ptr = jantee_buf;
        }

        c = *buff_ptr++;
        c_left--;

        /* Check if there is enough space in buffer */
        if (i >= *n - 1) {
            *n *= 2;  /* Double the buffer size */
            newPtr = (char *)_realloc(*lineptr, *n); 
            if (newPtr == NULL) {
                free(*lineptr);
                return -1;  /* Mem allocation failure */
            }
            *lineptr = newPtr;
        }

        /* Store character in buf */
        (*lineptr)[i++] = c;

        /* Check for newline char */
        if (c == '\n') {
            break;
        }
    }

    /* Null-terminate string */
    (*lineptr)[i] = '\0';

    return i;
}