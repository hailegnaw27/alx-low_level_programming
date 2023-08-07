#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/* Function to handle error and exit */
void handle_error(const char *error_message)
{
    perror(error_message);
    exit(EXIT_FAILURE);
}

/* Function to copy file_from to file_to */
void copy_file(const char *file_from, const char *file_to)
{
    int fd_from, fd_to, read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    /* Open file_from for reading */
    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        handle_error("Error: Can't read from file");

    /* Open file_to for writing */
    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_to == -1)
        handle_error("Error: Can't write to file");

    /* Copy content from file_from to file_to */
    while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes)
            handle_error("Error: Can't write to file");
    }

    /* Check for read error */
    if (read_bytes == -1)
        handle_error("Error: Can't read from file");

    /* Close file descriptors */
    if (close(fd_from) == -1 || close(fd_to) == -1)
        handle_error("Error: Can't close file descriptor");

    printf("File copied successfully.\n");
}

int main(int argc, char *argv[])
{
    /* Check for correct number of arguments */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Copy file */
    copy_file(argv[1], argv[2]);

    return 0;
}

