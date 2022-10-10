#include "rsa.h"


/**
  * main - program entry
  * @argc: argument count
  * @argv: vector
  *
  * Return: 0 in success, 1 on failure
  */
int main(int argc, char *argv[])
{
	(void)(argc);

	if (argv[1] == NULL)
	{
		fprintf(stderr, "Usage: ./rsa <file>\n");
		exit(1);
	}

	operate(argv[1]);
	exit(0);
}


/**
  * operate - extracts line from file and pass to handler
  * @str: pointer to file name
  *
  * Return: void
  */
void operate(char *str)
{
	FILE *file;
	char line[1024];
	long long digit;
	mpz_t n;

	mpz_init(n);
	file = fopen(str, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: could not open file:-> %s\n", str);
		exit(1);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line[strlen(line) - 1] = '\0';

		if (line[0] == '\0')
			continue;

		if (strlen(line) > 19)
		{
			mpz_set_str(n, line, 10);
			factorize(n);
		}
		else
		{
			digit = atoll(line);
			factorise((unsigned long long) digit);
		}
	}
	fclose(file);
}


/**
  * factorize - uses GNUmultiprecision library to factorize very large integers
  * @n: integer of type mpz_t
  *
  * Return: 1, always success
  */
int factorize(mpz_t n)
{
	mpz_t a, b, d, q, r;
	int i, flag, primes[] = {2, 3, 5, 7};

	mpz_init(a), mpz_init(b), mpz_init(d), mpz_init(q), mpz_init(r);
	for (i = 0; i < 4; i++)
	{
		mpz_set_si(d, primes[i]), mpz_mod(r, n, d), mpz_set_ui(a, 0);
		if (mpz_cmp(r, a) == 0)
		{
			mpz_divexact(q, n, d);
			mpz_out_str(stdout, 10, n), printf("=");
			mpz_out_str(stdout, 10, q), printf("*");
			mpz_out_str(stdout, 10, d), printf("\n");
			return (0);
		}
	}

	mpz_sqrtrem(q, r, n), mpz_add_ui(q, q, 1);
	mpz_mul(r, q, q), mpz_sub(d, r, n);
	flag = mpz_perfect_square_p(d);

	while (flag == 0)
	{
		mpz_add_ui(q, q, 1);
		mpz_mul(q, q, q);
		mpz_sub(d, q, n);
		flag = mpz_perfect_square_p(d);
	}
	mpz_sqrt(d, d), mpz_add(a, q, d), mpz_sub(b, q, d);
	mpz_out_str(stdout, 10, n), printf("=");
	mpz_out_str(stdout, 10, a), printf("*");
	mpz_out_str(stdout, 10, b), printf("\n");
	return (0);
}

/**
  * factorise - uses fermant's algorithm idea to factorise optimally
  * @n: integer
  *
  * Return: 1, always success
  */
int factorise(unsigned long long n)
{
	unsigned long long a, b;
	unsigned long long i, primes[] = {2, 3, 5, 7};

	for (i = 0; i < 4; i++)
	{
		if ((n % primes[i]) == 0)
		{
			b = n / primes[i];
			fprintf(stdout, "%llu=%llu*%llu\n", n, b, primes[i]);
			return (0);
		}
	}

	a = (unsigned long long) ceil(sqrt((double) n));
	b = (a * a) - n;
	a = (unsigned long long) ceil(sqrt((double) n));
	b = (a * a) - n;

	while (!square(b))
	{
		a++;
		b = (a * a) - n;
	}

	b = (unsigned long long) sqrt((double) b);

	fprintf(stdout, "%llu=%llu*%llu\n", n, a + b, a - b);
	return (0);
}

/**
  * square - helper to determine if a number has an integer square root
  * @b: integer
  *
  * Return: boolean, true if square else false
  */
bool square(unsigned long long b)
{
	double c;

	c = sqrt((double) b);

	if (ceil(c * c) == (double) b)
		return (true);
	return (false);
}

