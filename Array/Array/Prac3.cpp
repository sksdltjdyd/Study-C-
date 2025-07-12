#include <cstdio>

int main() {
	int multiarr[10][10];

	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			multiarr[i][k] = count + 1;
			count++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			printf("multiarr[%d][%d] = %d\n", i, k, multiarr[i][k]);
		}
		printf("\n");
	}

	return 0;
}