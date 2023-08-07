#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 1024

/**
* check_argc - checks the number of arguments
* @argc: number of arguments
*/
void check_argc(int argc)
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
}

/**
* open_files - opens the source and destination files
* @argv: array of arguments
* @fd_from: pointer to the file descriptor of the source file
* @fd_to: pointer to the file descriptor of the destination file
*/
void open_files(char *argv[], int *fd_from, int *fd_to)
{
mode_t mode;

/* open file_from */
*fd_from = open(argv[1], O_RDONLY);
if (*fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

/* open or create file_to */
mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
*fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (*fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(*fd_from);
exit(99);
}
}

/**
* copy_content - copies the content of a file to another file
* @fd_from: file descriptor of the source file
* @fd_to: file descriptor of the destination file
*/
void copy_content(int fd_from, int fd_to)
{
int rcount, wcount;
char buffer[BUFSIZE];

/* read and write 1024 bytes at a time */
while ((rcount = read(fd_from, buffer, BUFSIZE)) > 0)
{
wcount = write(fd_to, buffer, rcount);
if (wcount != rcount)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
close(fd_to);
exit(99);
}
}

/* check for read error */
if (rcount == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(fd_from);
close(fd_to);
exit(98);
}
}

/**
* close_files - closes the file descriptors
* @fd_from: file descriptor of the source file
* @fd_to: file descriptor of the destination file
*/
void close_files(int fd_from, int fd_to)
{
/* close file descriptors */
if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}

if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}
}

/**
* main - copies the content of a file to another file
* @argc: number of arguments
* @argv: array of arguments
* Return: 0 on success, exit with code on failure
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to;

check_argc(argc); /* check number of arguments */

open_files(argv, &fd_from, &fd_to); /* open files */

copy_content(fd_from, fd_to); /* copy content */

close_files(fd_from, fd_to); /* close files */

return (0);
}
