#include "shell.h"

int _atoi(const char *str) {
    int result = 0;
    int sign = 1;
    
    while (isspace(*str)) {
        str++;
    }

    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    while (isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}