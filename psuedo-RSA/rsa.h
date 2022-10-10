#ifndef RSA
#define RSA

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <gmp.h>

bool square(unsigned long long b);
int factorise(unsigned long long n);
int factorize(mpz_t n);
void operate(char *str);

#endif /* RSA */
