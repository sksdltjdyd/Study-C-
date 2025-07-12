#include <cstdio>

int main() {
	int arr1[5][5];
	int arr2[5][5];
	int arr3[5][5];
	int count = 1;

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++) {
			arr1[i][k] = count;
			count++;
		}
	}

	count = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++) {
			arr2[i][k] = count * 2;
			count++;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			arr3[i][k] = arr1[i][k] + arr2[i][k];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			printf("%d ", arr3[i][k]);
		}
		printf("\n");
	}

	return 0;
}