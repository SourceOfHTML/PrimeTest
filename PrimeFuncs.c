#include "PrimeFuncs.h"

int prime(long long *number)
{
	/*
	 * if n < 1,373,653, it is enough to test a = 2 and 3;
	 * if n < 25,326,001, it is enough to test a = 2, 3, and 5;
	 * if n < 3,215,031,751, it is enough to test a = 2, 3, 5, and 7;
	 * if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23;
	 * if n > 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37;
	 * Note that the last statement only works because long longs are 64 bit,
	 * If we had more range, then the statement would be false.
	 *
	 * This program only goes up to the three billion mark, because I cannot be arsed
	 */
	if ((*number) < 1373653)
	{
		int witnesses[2];
		witnesses[0] = 2;
		witnesses[1] = 3;
		return primality(number, witnesses, sizeof(witnesses) / sizeof(witnesses[0]));
	}
	if ((*number) < 25326001)
	{
		int witnesses[3];
		witnesses[0] = 2;
		witnesses[1] = 3;
		witnesses[2] = 5;
		return primality(number, witnesses, sizeof(witnesses) / sizeof(witnesses[0]));
	}
	if ((*number) < 3215031751)
	{
		int witnesses[4];
		witnesses[0] = 2;
		witnesses[1] = 3;
		witnesses[2] = 5;
		witnesses[3] = 7;
		return primality(number, witnesses, sizeof(witnesses) / sizeof(witnesses[0]));
	}
	return 0;
}

int primality(long long *number, int *witnesses, int array_size)
{
	long defendant = (*number) - 1;
	int powers_of_two = 0;
	while (!(defendant % 2))
	{
		defendant = defendant / 2;
		powers_of_two++;
	}
	for (int i = 0; i < array_size; i++)
	{
		if (witnesses[i] < defendant)
		{
			long long mod = power(witnesses + i, &defendant) % (*number);
			for (int j; j < powers_of_two; j++)
			{
				mod = (mod * mod) % (*number);
			}
			if (!(mod == 1 || mod == (*number) - 1))
			{
				return 0;
			}
		}
	}
	return 1;
}

long long power(int *number, long *power)
{
	long long result = 1;
	while ((*power) >= 1)
	{
		result = (*number) * result;
		*power = (*power) - 1;
	}
	return result;
}