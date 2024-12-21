#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PrimeFuncs.h"

int main(int argc, char **argv)
{
	long long input_number;
	if (argc < 2)
	{
		printf("Give us a number >:(\n");
		scanf("%lld", &input_number);
		getchar();
	}
	else
	{
		input_number = atoll(argv[1]);
	}

	if ((input_number & 1) == 0)
	{
		printf("Number is even. Sorry.\n");
		return 0;
	}
	if (input_number < 0)
	{
		printf("Negative numbers not allowed, sorry.\n");
		return 0;
	}

	if (!prime(&input_number))
	{
		printf("Sorry, not a prime.\n");
		return 0;
	}

	printf("Yes, %lld IS a prime number!\n", input_number);
	return 0;
}
