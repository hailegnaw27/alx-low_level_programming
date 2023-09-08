#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

/**
 * check_elf - Check if the file is an ELF file
 * @e_ident: ELF identification bytes
 */
void check_elf(unsigned char *e_ident)
{
    if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }
}

/**
 * print_magic - Print the ELF magic bytes
 * @e_ident: ELF identification bytes
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
 * print_class - Print the ELF class
 * @e_ident: ELF identification bytes
 */
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
        case ELFCLASSNONE:
            printf("None\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_CLASS]);
            break;
    }
}

/**
 * print_data - Print the ELF data encoding
 * @e_ident: ELF identification bytes
 */
void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
        case ELFDATANONE:
            printf("None\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_DATA]);
            break;
    }
}

/**
 * print_version - Print the ELF version
 * @e_ident: ELF identification bytes
 */
void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_abi - Print the ELF ABI
 * @e_ident: ELF identification bytes
 */
void print_abi(unsigned char *e_ident)
{
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_osabi - Print the ELF OS/ABI
 * @e_ident: ELF identification bytes
 */
void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("Standalone App\n");
            break;
        default:
            printf("<unknown: %x>\n", e_ident[EI_OSABI]);
            break;
    }
}

/**
 * print_type - Print the ELF file type
 * @e_type: ELF file type
 * @e_ident: ELF identification bytes
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
    printf("  Type:                              ");
    switch (e_type)
    {
        case ET_NONE:
            printf("NONE (Unknown type)\n");
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
            printf("<unknown: %x>\n", e_ident[EI_TYPE]);
            break;
    }
}

/**
 * print_entry - Print the ELF entry point address
 * @e_entry: ELF entry point address
 * @e_ident: ELF identification bytes
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("  Entry point address:               0x%lx\n", e_entry);
}

/**
 * close_elf - Close the ELF file
 * @elf: File descriptor of the ELF file
 */
void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot close file\n");
        exit(98);
    }
}

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    int elf;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
        return (98);
    }

    elf = open(argv[1], O_RDONLY);
    if (elf == -1)
    {
        dprintf(STDERR_FILENO, "Error: Cannot open file\n");
        return (98);
    }

    if (read(elf, &header, sizeof(header)) != sizeof(header))
    {
        dprintf(STDERR_FILENO, "Error: Cannot read file\n");
        close_elf(elf);
        return (98);
    }

    check_elf(header.e_ident);
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_abi(header.e_ident);
    print_osabi(header.e_ident);
    print_type(header.e_type, header.e_ident);
    print_entry(header.e_entry, header.e_ident);

    close_elf(elf);
    return (0);
}

