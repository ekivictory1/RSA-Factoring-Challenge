#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gmp.h>

/**
  * factor - factorization handler function
  * @p: integer pointer
  * @n: integer
  *
  * Return: void
  */
void factor(mpz_t *p, mpz_t n)
{
	mpz_t r;
	
	mpz_set_ui(*p, 2U);

	if (mpz_divisible_ui_p(n, 2U))
		return;

	mpz_init(r);
	mpz_sqrt(r, n);
	mpz_set_ui(*p, 3U);
	mpz_sqrt(r, n);

	while (!mpz_divisible_p(n, *p) && mpz_cmp(*p, r) < 0)
		mpz_add_ui(*p, *p, 2U);
		
	if (!mpz_divisible_p(n, *p))
		mpz_set(*p, n);

	mpz_clear(r);
}

/**
  * main - Entry
  * @ac: argument count
  * @av: string vector
  *
  * Return: integer
  */
int main(int ac, char **av)
{
	FILE *fp = NULL;
	char *line = NULL;
	size_t line_size = 0;
	ssize_t line_length = -1;
	mpz_t n, p, q, r;

	mpz_init(n);
	mpz_init(p);
	mpz_init(q);
	mpz_init(r);

	if (ac != 2)
	{
		fprintf(stderr, "Error: usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	
	if (!fp)
	{
		fprintf(stderr, "Error: cannot open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_length = getline(&line, &line_size, fp)) != -1)
	{
		line[line_length - 1] = '\0';
		
		mpz_set_str(n, line, 10);

		factor(&p, n);
		mpz_tdiv_q(q, n, p);

		mpz_out_str(stdout, 10, n);
		printf("=");
		mpz_out_str(stdout, 10, q);
		printf("*");
		mpz_out_str(stdout, 10, p);
		printf("\n");
	}

	free(line);
	fclose(fp);

	mpz_clear(n);
	mpz_clear(p);
	mpz_clear(q);
	mpz_clear(r);

	return (0);
}

