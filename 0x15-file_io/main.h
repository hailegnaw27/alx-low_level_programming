#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>

/* File 0-read_textfile.c */
ssize_t read_textfile(const char *filename, size_t letters);

/* File 1-create_file.c */
int create_file(const char *filename, char *text_content);

/* File 2-append_text_to_file.c */
int append_text_to_file(const char *filename, char *text_content);

/* File 3-cp.c */
int cp_file(const char *file_from, const char *file_to);
void print_error(int code, const char *msg);
void error_exit(char *msg, char *file, int fd, int code);
void print_usage_error(void);
void print_read_error(char *filename);
void print_write_error(char *filename);
void print_close_error(int fd);
int main(int argc, char *argv[]);
/* Helper function */
int _putchar(char c);

#endif /* MAIN_H */
