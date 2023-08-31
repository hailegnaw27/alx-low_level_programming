/**
 * flip_bits - Returns the number of bits to flip.
 * @n: First number
 * @m: Second number
 *
 * Return: Number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int xor_result = n ^ m;  /* XOR the two numbers */
    unsigned int count = 0;

    while (xor_result > 0)
    {
        if (xor_result & 1)  /* Check if the least significant bit is set */
            count++;

        xor_result >>= 1;  /* Shift right to check the next bit */
    }

    return count;
}

