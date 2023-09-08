#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_usage_error - Prints the usage error message and exits.
 */
void print_usage_error(void)
{
    dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
    exit(97);
}

/**
 * print_read_error - Prints the read error message and exits.
 * @filename: The name of the file that couldn't be read.
 */
void print_read_error(char *filename)
{
    dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
    exit(98);
}

/**
 * print_write_error - Prints the write error message and exits.
 * @filename: The name of the file that couldn't be written to.
 */
void print_write_error(char *filename)
{
    dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
    exit(99);
}

/**
 * print_close_error - Prints the close error message and exits.
 * @fd: The file descriptor that couldn't be closed.
 */
void print_close_error(int fd)
{
    dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
    exit(100);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, otherwise exit with an error code
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        print_usage_error();

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        print_read_error(argv[1]);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        print_write_error(argv[2]);

    while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes == -1 || write_bytes != read_bytes)
            print_write_error(argv[2]);
    }

    if (read_bytes == -1)
        print_read_error(argv[1]);

    if (close(fd_from) == -1)
        print_close_error(fd_from);

    if (close(fd_to) == -1)
        print_close_error(fd_to);

    return 0;
}

