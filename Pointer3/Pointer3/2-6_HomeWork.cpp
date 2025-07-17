#include "Header.h"

int main() {
	int input;
	printf("Enter a number : ");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);

	int* par = (int*)malloc(sizeof(int) * input);

	for (int i = 0; i < input; i++)
	{
		par[i] = 2 + (i * 2);
	}

	for (int i = 0; i < input; i++)
	{
		printf("par[%d] = %d\n", i, par[i]);
	}

	free(par);
	return 0;
}