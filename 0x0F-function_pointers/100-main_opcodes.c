#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 on incorrect number of arguments,
 *         2 on negative number of bytes
 */
int main(int argc, char *argv[])
{
    int i, num_bytes;

    if (argc != 2)
    {
        printf("Error\n");
        return (1);
    }

    num_bytes = atoi(argv[1]);

    if (num_bytes < 0)
    {
        printf("Error\n");
        return (2);
    }

    unsigned char *ptr = (unsigned char *)main;
    for (i = 0; i < num_bytes; i++)
        printf("%02x ", ptr[i]);
    printf("\n");

    return (0);
}

