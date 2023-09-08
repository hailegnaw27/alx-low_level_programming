#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_elf_header - Prints the information contained in the ELF header.
 * @header: A pointer to the ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *header)
{
  int i;

  printf("ELF Header:\n");
  printf("Magic: ");
  for (i = 0; i < EI_NIDENT; i++)
    printf("%02x ", header->e_ident[i]);
  printf("\n");
  printf("Class: %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
  printf("Data: %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
  printf("Version: %d (current)\n", header->e_ident[EI_VERSION]);
  printf("OS/ABI: ");
  switch (header->e_ident[EI_OSABI])
  {
    case ELFOSABI_SYSV:
      printf("UNIX - System V\n");
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
    default:
      printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
      break;
  }
  printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
  printf("Type: ");
  switch (header->e_type)
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
    default:
      printf("<unknown: %d>\n", header->e_type);
      break;
  }
  printf("Entry point address: 0x%lx\n", header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char **argv)
{
  int file_descriptor;
  Elf64_Ehdr header;

  if (argc != 2)
  {
    dprintf(2, "Usage: %s elf_filename\n", argv[0]);
    exit(98);
  }

  file_descriptor = open(argv[1], O_RDONLY);
  if (file_descriptor == -1)
  {
    dprintf(2, "Error: Cannot open file %s\n", argv[1]);
    exit(98);
  }

  if (read(file_descriptor, &header, sizeof(header)) != sizeof(header))
  {
    dprintf(2, "Error: Cannot read ELF header from file %s\n", argv[1]);
    close(file_descriptor);
    exit(98);
  }

  print_elf_header(&header);

  close(file_descriptor);
  return (0);
}

