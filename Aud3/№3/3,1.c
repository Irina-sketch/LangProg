#include <stdio.h>
#include <stdlib.h>
int main()
{
	int size = 0,size2=0;	
	scanf_s("%d", &size);
	printf_s("\n");
	int *mass = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &mass[i]);
	}
	size2 = size;
	for (int n = 0; n < size; n++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (mass[i] == mass[j])
				{
					size--;
					for (int l = j; l < size2 - 1; l++)
					{
						int tmp = mass[l];
						mass[l] = mass[l + 1];
						mass[l + 1] = tmp;
					}
				}
			}

		}
	}
	int *mass2 = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		mass2[i] = mass[i];
	}
	for (int i = 0; i < size; i++)
	{
		printf_s(" %d ", mass2[i]);
	}
	free(mass2);
	free(mass);
	system("pause");
	return 0;
}