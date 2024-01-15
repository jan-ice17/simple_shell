#include "shell.h"


/**
 * Reads a line from a file descriptor and stores it in a dynamically allocated buffer.
 *
 * @param lineptr Pointer to the buffer where the line will be stored.
 * @param n Pointer to the size of the buffer.
 * @param fd File descriptor to read from.
 * @return The number of characters read, or -1 if an error occurred.
 */
ssize_t _getline(char **lineptr, size_t *n, int fd) {
    static char jan_buf[BUFFER_SIZE];
    static char *p;
    static ssize_t size;
    char *line;
    size_t len;

    if (p == NULL || p > jan_buf + size) {
        size = read(fd, jan_buf, BUFFER_SIZE);
        if (size <= 0) {
            return -1;
        }
        p = jan_buf;
    }

    line = malloc(size + 1);
    if (line == NULL) {
        return -1;
    }

    len = 0;
    while (size > 0) {
        line[len++] = *p++;
        size--;
        if (line[len - 1] == '\n') {
            break;
        }
    }

    line[len] = '\0';
    *lineptr = line;
    if (n != NULL) {
        *n = len;
    }

    return len;
}