#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

void error_exit(char *msg, char *file, int fd, int code)
{
	dprintf(STDERR_FILENO, msg, file);
	if (fd != -1)
		close(fd);
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
	if (argc != 3)
		error_exit("Usage: cp file_from file_to\n", NULL, -1, 97);

	int fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit("Error: Can't read from file %s\n", argv[1], -1, 98);

	int fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit("Error: Can't write to %s\n", argv[2], fd_from, 99);

	char buffer[BUFFER_SIZE];
	ssize_t read_chars, write_chars;

	while ((read_chars = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_chars = write(fd_to, buffer, read_chars);
		if (write_chars != read_chars)
			error_exit("Error: Can't write to %s\n", argv[2], fd_from, 99);
	}

	if (read_chars == -1)
		error_exit("Error: Can't read from file %s\n", argv[1], fd_from, 98);

	close(fd_from) == -1 ? error_exit("Error: Can't close fd %d\n", NULL, fd_from, 100) : 0;
	close(fd_to) == -1 ? error_exit("Error: Can't close fd %d\n", NULL, fd_to, 100) : 0;

	return (0);
}

