#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * display_elf_header - Display information from ELF header
 * @filename: The name of the ELF file
 */
void display_elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	Elf64_Ehdr header;

	if (fd == -1)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		fprintf(stderr, "Error reading ELF header\n");
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header.e_ident[i]);
	printf("\n");

	printf("  Class: ");
	switch (header.e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}

	printf("  Data: ");
	switch (header.e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}

	printf("  Version: %d (current)\n", header.e_ident[EI_VERSION]);

	printf("  OS/ABI: ");
	switch (header.e_ident[EI_OSABI])
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
		printf("Unknown\n");
		break;
	}

	printf("  ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);

	printf("  Type: ");
	switch (header.e_type)
	{
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}

	printf("  Entry point address: 0x%lx\n", header.e_entry);

	close(fd);
}

/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: (0) on success, (1) on error
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}

	display_elf_header(argv[1]);

	return (0);
}

