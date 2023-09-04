#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * print_error - Prints the error message and exits with the given code
 * @code: The exit code
 * @msg: The error message
 */
void print_error(int code, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, otherwise a positive integer
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd, wr;
	char buffer[BUF_SIZE];

	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file");

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		print_error(99, "Error: Can't write to file");

	while ((rd = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr == -1 || wr != rd)
			print_error(99, "Error: Can't write to file");
	}

	if (rd == -1)
		print_error(98, "Error: Can't read from file");

	if (close(fd_from) == -1)
		print_error(100, "Error: Can't close file descriptor");

	if (close(fd_to) == -1)
		print_error(100, "Error: Can't close file descriptor");

	return (0);
}

