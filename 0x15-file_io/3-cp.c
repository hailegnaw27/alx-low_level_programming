#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 1024

/**
* main - copies the content of a file to another file
* @argc: number of arguments
* @argv: array of arguments
* Return: 0 on success, exit with code on failure
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to, rcount, wcount;
char buffer[BUFSIZE];
mode_t mode;

/* check number of arguments */
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

/* open file_from */
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

/* open or create file_to */
mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
exit(99);
}

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

return (0);
}
