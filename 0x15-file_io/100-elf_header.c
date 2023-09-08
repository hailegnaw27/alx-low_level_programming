#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
* check_elf - Checks if the file is an ELF file
* @e_ident: Pointer to the ELF identification bytes
*/
void check_elf(unsigned char *e_ident);

/**
* print_magic - Prints the ELF magic bytes
* @e_ident: Pointer to the ELF identification bytes
*/
void print_magic(unsigned char *e_ident);

/**
* print_class - Prints the ELF class
* @e_ident: Pointer to the ELF identification bytes
*/
void print_class(unsigned char *e_ident);

/**
* print_data - Prints the ELF data encoding
* @e_ident: Pointer to the ELF identification bytes
*/
void print_data(unsigned char *e_ident);

/**
* print_version - Prints the ELF version
* @e_ident: Pointer to the ELF identification bytes
*/
void print_version(unsigned char *e_ident);

/**
* print_abi - Prints the ELF operating system and ABI
* @e_ident: Pointer to the ELF identification bytes
*/
void print_abi(unsigned char *e_ident);

/**
* print_osabi - Prints the ELF ABI version
* @e_ident: Pointer to the ELF identification bytes
*/
void print_osabi(unsigned char *e_ident);

/**
* print_type - Prints the ELF file type
* @e_type: ELF file type
* @e_ident: Pointer to the ELF identification bytes
*/
void print_type(unsigned int e_type, unsigned char *e_ident);

/**
* print_entry - Prints the ELF entry point address
* @e_entry: ELF entry point address
* @e_ident: Pointer to the ELF identification bytes
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/**
* close_elf - Closes the ELF file descriptor
* @elf: ELF file descriptor
*/
void close_elf(int elf);

/**
* main - Entry point of the program
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: 0 on success, 98 on error
*/
int main(int argc, char *argv[])
{
int elf;
unsigned char e_ident[16];

if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

elf = open(argv[1], O_RDONLY);
if (elf == -1)
{
fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
exit(98);
}

if (read(elf, e_ident, sizeof(e_ident)) != sizeof(e_ident))
{
fprintf(stderr, "Error: Cannot read ELF header\n");
close_elf(elf);
exit(98);
}

check_elf(e_ident);
print_magic(e_ident);
print_class(e_ident);
print_data(e_ident);
print_version(e_ident);
print_abi(e_ident);
print_osabi(e_ident);
print_type(*(unsigned int *)(e_ident + 16), e_ident);
print_entry(*(unsigned long int *)(e_ident + 24), e_ident);

close_elf(elf);
return (0);
}

/**
* check_elf - Checks if the file is an ELF file
* @e_ident: Pointer to the ELF identification bytes
*/
void check_elf(unsigned char *e_ident)
{
if (e_ident[0] != 0x7f || e_ident[1] != 'E' || 
		e_ident[2] != 'L' || e_ident[3] != 'F')
{
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
}
}

/**
* print_magic - Prints the ELF magic bytes
* @e_ident: Pointer to the ELF identification bytes
*/
void print_magic(unsigned char *e_ident)
{
printf("Magic:   ");
for (int i = 0; i < 16; i++)
{
printf("%02x ", e_ident[i]);
}
printf("\n");
}

/**
* print_class - Prints the ELF class
* @e_ident: Pointer to the ELF identification bytes
*/
void print_class(unsigned char *e_ident)
{
printf("Class:                             ");
if (e_ident[4] == 1)
{
printf("ELF32\n");
}
else if (e_ident[4] == 2)
{
printf("ELF64\n");
}
else
{
printf("<unknown>\n");
}
}

/**
* print_data - Prints the ELF data encoding
* @e_ident: Pointer to the ELF identification bytes
*/
void print_data(unsigned char *e_ident)
{
printf("Data:                              ");
if (e_ident[5] == 1)
{
printf("2's complement, little endian\n");
}
else if (e_ident[5] == 2)
{
printf("2's complement, big endian\n");
}
else
{
printf("<unknown>\n");
}
}

/**
* print_version - Prints the ELF version
* @e_ident: Pointer to the ELF identification bytes
*/
void print_version(unsigned char *e_ident)
{
printf("Version:                %d (current)\n", e_ident[6]);
}

/**
* print_abi - Prints the ELF operating system and ABI
* @e_ident: Pointer to the ELF identification bytes
*/
void print_abi(unsigned char *e_ident)
{
printf("OS/ABI:                            ");
switch (e_ident[7])
{
case 0:
printf("UNIX - System V\n");
break;
case 1:
printf("HP-UX\n");
break;
case 2:
printf("NetBSD\n");
break;
case 3:
printf("Linux\n");
break;
case 6:
printf("Solaris\n");
break;
case 7:
printf("AIX\n");
break;
case 8:
printf("IRIX\n");
break;
case 9:
printf("FreeBSD\n");
break;
case 10:
printf("Tru64\n");
break;
case 11:
printf("Novell Modesto\n");
break;
case 12:
printf("OpenBSD\n");
break;
case 13:
printf("OpenVMS\n");
break;
case 14:
printf("NonStop Kernel\n");
break;
case 15:
printf("AROS\n");
break;
case 16:
printf("Fenix OS\n");
break;
case 17:
printf("CloudABI\n");
break;
default:
printf("<unknown>\n");
break;
}
}

/**
* print_osabi - Prints the ELF ABI version
* @e_ident: Pointer to the ELF identification bytes
*/
void print_osabi(unsigned char *e_ident)
{
printf("ABI Version:                       %d\n", e_ident[8]);
}

/**
* print_type - Prints the ELF file type
* @e_type: ELF file type
* @e_ident: Pointer to the ELF identification bytes
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
printf("Type:                              ");
switch (e_type)
{
case 0:
printf("NONE (No file type)\n");
break;
case 1:
printf("REL (Relocatable file)\n");
break;
case 2:
printf("EXEC (Executable file)\n");
break;
case 3:
printf("DYN (Shared object file)\n");
break;
case 4:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown>\n");
break;
}
}

/**
* print_entry - Prints the ELF entry point address
* @e_entry: ELF entry point address
* @e_ident: Pointer to the ELF identification bytes
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("Entry point address:               0x%lx\n", e_entry);
}

/**
* close_elf - Closes the ELF file descriptor
* @elf: ELF file descriptor
*/
void close_elf(int elf)
{
if (close(elf) == -1)
{
fprintf(stderr, "Error: Cannot close file\n");
exit(98);
}
}
