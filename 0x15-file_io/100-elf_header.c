#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * error_exit - Prints an error message and exits with status code 98.
 * @message: The error message to print.
 */
void error_exit(char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header.
 * @header: A pointer to the ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *header)
{
    int i;

    printf("ELF Header:\n");
    printf("  Magic: ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");
    printf("  Class: %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("  Data: %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version: %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI: ");
    switch (header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        default: printf("<unknown: %d>\n", header->e_ident[EI_OSABI]); break;
    }
    printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type: ");
    switch (header->e_type)
    {
        case ET_NONE: printf("NONE (Unknown type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        default: printf("<unknown: %d>\n", header->e_type); break;
    }
    printf("  Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
	}
}

/**
 * elf_header - Displays the information contained in the ELF header of a file.
 * @filename: The name of the ELF file.
 */
void elf_header(char *filename)
{
    int fd;
    Elf64_Ehdr header;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error_exit("Error: Cannot open file");

    if (read(fd, &header, sizeof(header)) != sizeof(header))
        error_exit("Error: Cannot read ELF header");

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
        error_exit("Error: Not an ELF file");

    print_elf_header(&header);

    close(fd);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}


/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 on error.
 */



int main(int argc, char **argv)
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return (98);
    }

    elf_header(argv[1]);

    return (0);
}

