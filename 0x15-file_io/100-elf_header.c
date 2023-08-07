#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 64

/**
 * print_magic - prints the magic bytes of an ELF header
 * @buffer: a buffer containing the ELF header
 */
void print_magic(char *buffer)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < 16; i++)
    {
        printf("%02x", buffer[i] & 0xff);
        if (i < 15)
            printf(" ");
    }
    printf("\n");
}

/**
 * print_class - prints the class of an ELF header
 * @buffer: a buffer containing the ELF header
 */
void print_class(char *buffer)
{
    printf("  Class:                             ");
    switch (buffer[4])
    {
        case 0:
            printf("none\n");
            break;
        case 1:
            printf("ELF32\n");
            break;
        case 2:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", buffer[4]);
            break;
    }
}

/**
 * print_data - prints the data of an ELF header
 * @buffer: a buffer containing the ELF header
 */
void print_data(char *buffer)
{
    printf("  Data:                              ");
    switch (buffer[5])
    {
        case 0:
            printf("none\n");
            break;
        case 1:
            printf("2's complement, little endian\n");
            break;
        case 2:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", buffer[5]);
            break;
    }
}

/**
 * print_version - prints the version of an ELF header
 * @buffer: a buffer containing the ELF header
 */
void print_version(char *buffer)
{
    printf("  Version:                           ");
    switch (buffer[6])
    {
        case 0:
            printf("0 (invalid)\n");
            break;
        case 1:
            printf("1 (current)\n");
            break;
        default:
            printf("%d\n", buffer[6]);
            break;
    }
}

/**
 * print_osabi - prints the OS/ABI of an ELF header
 * @buffer: a buffer containing the ELF header
 */
void print_osabi(char *buffer)
{
    printf("  OS/ABI:                            ");
    switch (buffer[7])
    {
        case 0:
            printf("UNIX - System V\n");
            break;
        case 1:
            printf("UNIX - HP-UX\n");
            break;
        case 2:
            printf("UNIX - NetBSD\n");
            break;
        case 3:
            printf("UNIX - Linux\n");
            break;
        case 4:
            printf("UNIX - GNU Hurd\n");
            break;
        case 6:
            printf("UNIX - Solaris\n");
            break;
        case 7:
            printf("UNIX - AIX\n");
            break;
        case 8:
            printf("UNIX - IRIX\n");
            break;
        case 9:
            printf("UNIX - FreeBSD\n");
            break;
        case 10:
            printf("UNIX - Tru64\n");
            break;
        case 11:
            printf("Novell - Modesto\n");
            break;
        case 12:
            printf("Novell - OpenBSD\n");
            break;
        case 13:
            printf("Open VMS\n");
            break;
        case 14:
            printf("Hewlett-Packard - Non-Stop Kernel\n");
            break;
        case 15:
            printf("Amiga - AmigaOS\n");
            break;
        default:
           if (buffer[7] >=64 && buffer[7] <=255)
                printf("<unknown: %x>\n", buffer[7]);
           else
                printf("<unknown>\n"); 
           break; 
    }
}

/**
 * print_abiversion - prints the ABI version of an ELF header
 * @buffer: a buffer containing the ELF header
 */
void print_abiversion(char *buffer)
{
    printf("  ABI Version:                       ");
    switch (buffer[8])
    {
        default:
           if (buffer[8] >=0 && buffer[8] <=255)
                printf("%d\n", buffer[8]);
        else
                printf("<unknown>\n"); 
           break; 
    }
}

/**
 * print_type - prints the type of an ELF header
 * @buffer: a buffer containing the ELF header
 */
void print_type(char *buffer)
{
    int type;

    printf("  Type:                              ");
    type = buffer[16] + (buffer[17] << 8);
    switch (type)
    {
        case 0:
            printf("NONE (Unknown type)\n");
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
           if (type >= 0xfe00 && type <= 0xfeff)
                printf("OS Specific: (%x)\n", type);
           else if (type >= 0xff00 && type <= 0xffff)
                printf("Processor Specific: (%x)\n", type);
           else
                printf("<unknown: %x>\n", type);
           break; 
    }
}

/**
 * print_entry - prints the entry point address of an ELF header
 * @buffer: a buffer containing the ELF header
 */
void print_entry(char *buffer)
{
    unsigned long int entry;

    printf("  Entry point address:               ");
    entry = buffer[24] + (buffer[25] << 8) + (buffer[26] << 16) + (buffer[27] << 24);
    if (buffer[4] == 2) /* ELF64 */
        entry += ((unsigned long int)buffer[28] << 32) + ((unsigned long int)buffer[29] << 40) +
                 ((unsigned long int)buffer[30] << 48) + ((unsigned long int)buffer[31] << 56);
    printf("%#lx\n", entry);
}

/**
 * main - displays the information contained in the ELF header at the start of an ELF file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, exit with code on failure
 */
int main(int argc, char *argv[])
{
    int fd, rcount;
    char buffer[BUFSIZE];

    /* check number of arguments */
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    /* open file */
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    /* read ELF header */
    rcount = read(fd, buffer, BUFSIZE);
    if (rcount == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd);
        exit(98);
    }

    /* check magic bytes */
    if (buffer[0] != 0x7f || buffer[1] != 'E' || buffer[2] != 'L' || buffer[3] != 'F')
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file - it has the wrong magic bytes at the start\n");
        close(fd);
        exit(98);
    }

    /* print ELF header information */
    printf("ELF Header:\n");
    
    print_magic(buffer); /* print magic bytes */

    print_class(buffer); /* print class */

    print_data(buffer); /* print data */

    print_version(buffer); /* print version */

    print_osabi(buffer); /* print OS/ABI */

    print_abiversion(buffer); /* print ABI version */

    print_type(buffer); /* print type */

    print_entry(buffer); /* print entry point address */

    /* close file */
    close(fd);

    return (0);
}

