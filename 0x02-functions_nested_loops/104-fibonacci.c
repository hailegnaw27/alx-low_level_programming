int main(void)
{
int a = 1, b = 2, c, i;

_putchar('1');
_putchar(',');
_putchar(' ');
_putchar('2');

for (i = 3; i <= 98; i++)
{
c = a + b;
_putchar(',');
_putchar(' ');
printf("%d", c);
a = b;
b = c;
}

_putchar('\n');

return (0);
}
