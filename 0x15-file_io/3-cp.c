#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_error - Prints the error message and exits with the given code
 * @code: The exit code
 * @msg: The error message
 *
 * Return: None
 */
void print_error(int code, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * open_file - Opens a file with the given flags
 * @filename: The name of the file to open
 * @flags: The flags to use when opening the file
 *
 * Return: The file descriptor of the opened file
 */
int open_file(const char *filename, int flags)
{
	int fd = open(filename, flags);
	if (fd == -1)
		print_error(98, "Error: Can't read from file");

	return (fd);
}

/**
 * write_file - Writes data to a file
 * @fd: The file descriptor of the file to write to
 * @filename: The name of the file being written to (for error messages)
 * @buffer: The buffer containing the data to write
 * @size: The size of the data to write
 *
 * Return: None
 */
void write_file(int fd, const char *filename, const char *buffer, ssize_t size)
{
	ssize_t written = write(fd, buffer, size);
	if (written == -1 || written != size)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}

/**
 * copy_file - Copies the content of one file to another file
 * @file_from: The name of the file to copy from
 * @file_to: The name of the file to copy to
 *
 * Return: None
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t read_chars;

	fd_from = open_file(file_from, O_RDONLY);
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		print_error(99, "Error: Can't write to file");

	while ((read_chars = read(fd_from, buffer, BUFFER_SIZE)) > 0)
		write_file(fd_to, file_to, buffer, read_chars);

	if (read_chars == -1)
		print_error(98, "Error: Can't read from file");

	if (close(fd_from) == -1)
		print_error(100, "Error: Can't close file descriptor");

	if (close(fd_to) == -1)
		print_error(100, "Error: Can't close file descriptor");
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 97 on incorrect number of arguments
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

