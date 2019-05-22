#include "pch.h"
#include <iostream>
#include <stdio.h>

int main(void) 
{
	int i, j, n;
	scanf("%d", &n);
	char a[n];

	for (i = 1; i <= n; i++)
		a[i] = 1;

	for (i = 1; 2 * i*(i + 1) < n; i++)
		for (j = i; j <= (n - i) / (2 * i + 1); j++)
			a[2 * i*j + i + j] = 0;

	for (i = 0; i < n; i++)
		if (a[i])
			printf("%d ", 2 * i + 1);
	return 0;
}