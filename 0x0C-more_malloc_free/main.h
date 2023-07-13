#ifndef MAIN_H
#define MAIN_H   

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloic(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _putchar(char c);
int is_positive_number(const char* str);
int main(int argc, char* argv[]);
int validate_arguments(int argc, char *argv[]);
#endif /* MAIN_H */

