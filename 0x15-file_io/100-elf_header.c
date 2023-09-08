#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUF_SIZE 128

/**
 * error_exit - Print error message and exit with status code 98
 * @msg: Error message to print
 */
void error_exit(char *msg)
{
    dprintf(STDERR_FILENO, "%s\n", msg);
    exit(98);
}

/**
 * print_magic - Print the magic bytes of the ELF header
 * @e_ident: Pointer to the ELF identification bytes
 */
void print_magic(unsigned char *e_ident)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

/**
 * print_class - Print the ELF class (32-bit or 64-bit)
 * @e_ident: Pointer to the ELF identification bytes
 */
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("ELF32\n");
    else if (e_ident[EI_CLASS] == ELFCLASS64)
        printf("ELF64\n");
    else
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
 * print_data - Print the endianness of the ELF file
 * @e_ident: Pointer to the ELF identification bytes
 */
void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    if (e_ident[EI_DATA] == ELFDATA2LSB)
        printf("2's complement, little endian\n");
    else if (e_ident[EI_DATA] == ELFDATA2MSB)
        printf("2's complement, big endian\n");
    else
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
}

/**
 * print_version - Print the ELF version
 * @e_ident: Pointer to the ELF identification bytes
 */
void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Print the OS/ABI of the ELF file
 * @e_ident: Pointer to the ELF identification bytes
 */
void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_OSABI]);
            break;
    }
}

/**
 * print_type - Print the type of the ELF file
 * @e_type: Type of the ELF file
 */
void print_type(unsigned int e_type)
{
    printf("  Type:                              ");
    switch (e_type)
    {
        case ET_NONE:
            printf("NONE (No file type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown: %x>\n", e_type);
            break;
    }
}

/**
 * print_entry - Print the entry point address of the ELF file
 * @e_entry: Entry point address
 */
void print_entry(unsigned long int e_entry)
{
    printf("  Entry point address:               %#lx\n", e_entry);
}

/**
 * print_elf_header - Print the information contained in the ELF header
 * @fd: File descriptor of the ELF file
 */
void print_elf_header(int fd)
{
    Elf64_Ehdr header;
    ssize_t bytes_read;

    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read == -1)
        error_exit("Error reading ELF header");

    if (bytes_read != sizeof(header))
        error_exit("Incomplete ELF header");

    printf("ELF Header:\n");
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_type(header.e_type);
    print_entry(header.e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
        error_exit("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        error_exit("Error opening file");

    print_elf_header(fd);

    if (close(fd) == -1)
        error_exit("Error closing file");

    return 0;
}

