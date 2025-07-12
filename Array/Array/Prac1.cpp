#include <cstdio>

int main() {

	int Myarray[20];

	for (int i = 0; i < 20; i++)
	{
		Myarray[i] = (i + 1) * 2;
	}

	for (int k = 0; k < 20; k++)
	{
		printf("Myarray[%d] = %d\n", k, Myarray[k]);
	}
	return 0;
}