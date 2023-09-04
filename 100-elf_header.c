#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits with status code 98
 * @msg: The error message
 */
void error_exit(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("ELFCLASSNONE\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("Unknown data format\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
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
		printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
		break;
	}
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
	case ET_NONE:
		printf("No file type\n");
		break;
	case ET_REL:
		printf("Relocatable file\n");
		break;
	case ET_EXEC:
		printf("Executable file\n");
		break;
	case ET_DYN:
		printf("Shared object file\n");
		break;
	case ET_CORE:
		printf("Core file\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd, read_chars;
	Elf64_Ehdr header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Can't read from file");

	read_chars = read(fd, &header, sizeof(header));
	if (read_chars == -1)
		error_exit("Error: Can't read from file");

	if (read_chars != sizeof(header))
		error_exit("Error: Not a valid ELF file");

	print_elf_header(&header);

	if (close(fd) == -1)
		error_exit("Error: Can't close file");

	return (0);
}

