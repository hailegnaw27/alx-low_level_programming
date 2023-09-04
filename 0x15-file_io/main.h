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

/* Helper function */
int _putchar(char c);

#endif /* MAIN_H */

