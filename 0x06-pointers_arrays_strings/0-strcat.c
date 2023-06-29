#include "main.h"
#include <stdio.h>

/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to the resulting string `dest`
 */
char *_strcat(char *dest, char *src)
{
    int i, j;

    /* Find the end of the destination string */
    i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }

    /* Concatenate the source string to the destination string */
    j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* Add the null terminator at the end */
    dest[i] = '\0';

    return dest;
}

