#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * gcd - function that computes the greatest common divisor
 * @a: divisor 1
 * @b: divisor
 * 
 * Return: a
 */

unsigned long gcd(unsigned long a, unsigned long b)
{
	unsigned long temp;

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

/**
 * pollards_rho - function attempts to find a factor of the number n
 *  using a pseudo-random process
 * @n: number to factorize
 * 
 * Return: 1
 */

unsigned long pollards_rho(unsigned long n)
{
	unsigned long x = rand() % n + 1;
	unsigned long y = x;
	unsigned long c = rand() % n + 1;
	unsigned long d = 1;
    int i = 0;

	if (n % 2 == 0)
		return (2);

	while (d == 1 && 1 < 1000000)
	{
		x = (x * x + c) % n;
		y = (y * y + c) % n;
		y = (y * y + c) % n;
		d = gcd(abs(x - y), n);
		i++;
	}
	return (d == n ? 0 : d);
}

/**
 * factorize - Factorize using trial division by primes
 * @n: input numbers
 */

void factorize(unsigned long n)
{
	unsigned long div;
	
	if (n <= 1)
		return;
	if (n % 2 == 0)
	{
		printf("%lu=2*%lu\n", n, n / 2);
		return;
	}

	div = pollards_rho(n);
	
	if (div == 0 || div == n)
	{
		printf("%lu=%lu*1\n", n, n);
	}
	else
	{
		printf("%lu=%lu*%lu\n", n, n / div, div);
	}
}

/**
 * main - entry to main function
 * @argc: input arguments
 * @argv: pointer to arguments
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
	unsigned long n;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");
	
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(file, "%lu", &n) == 1)
	{
		if (n > 1)
		{
			factorize(n);
		}
	}

	fclose(file);
	return (0);
}
