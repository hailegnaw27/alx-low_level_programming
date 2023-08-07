#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * error_exit - Prints an error message and exits the program.
 * @message: The error message to print.
 * @code: The exit code.
 */
void error_exit(const char *message, int code)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, or the appropriate exit code on failure.
 */
int main(int argc, char *argv[])
{
    int file_from, file_to, read_count, write_count;
    char buffer[1024];

    if (argc != 3)
        error_exit("Usage: cp file_from file_to", 97);

    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
        error_exit("Error: Can't read from file", 98);

    file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_to == -1)
        error_exit("Error: Can't write to file", 99);

    while ((read_count = read(file_from, buffer, sizeof(buffer))) > 0)
    {
        write_count = write(file_to, buffer, read_count);
        if (write_count == -1)
            error_exit("Error: Can't write to file", 99);
        if (write_count < read_count)
            error_exit("Error: Can't write to file", 99);
    }

    if (read_count == -1)
        error_exit("Error: Can't read from file", 98);

    if (close(file_from) == -1)
        error_exit("Error: Can't close file descriptor", 100);

    if (close(file_to) == -1)
        error_exit("Error: Can't close file descriptor", 100);

    return 0;
}

