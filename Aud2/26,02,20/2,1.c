#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <locale.h>
typedef struct
{
	int age;
	char name[20];
	char surname[20];
}person;

int main()
{
	setlocale(LC_ALL, "Rus");
	FILE* A;
	fopen_s(&A, "A.txt", "r");
	int number;
	fscanf_s(A, "%d", &number);
	person* MASS;
	MASS = (person*)malloc(number * sizeof(person));
	for (int i = 0; i < number; i++)
	{
		fscanf_s(A, "%d", &(MASS[i].age));
		int j = 0, k = 0;
		char c;
		getc(A);
		while ((c = getc(A)) != 32)
		{
			MASS[i].name[j] = c;
			j++;
		}
		MASS[i].name[j] = '\0';
		while (((c = getc(A)) != '\n') && (c != EOF))
		{
			MASS[i].surname[k] = c;
			k++;
		}
		MASS[i].surname[k] = '\0';
	}
	for (int i = 0; i < number; i++)
	{
		printf("%d ", MASS[i].age);
		int j = 0, k = 0;
		char c;
		while ((c = MASS[i].name[j]) != '\0')
		{
			printf("%c", c);
			j++;
		}
		printf(" ");
		while ((c = MASS[i].surname[k]) != '\0')
		{
			printf("%c", c);
			k++;
		}
		printf("\n");
	}
	int MAX = 0, num = 0;
	for (int i = 0; i < number; i++)
	{
		if (MASS[i].age > MAX)
		{
			MAX = MASS[i].age;
			num = i;
		}
	}
	printf("MAX= %d ", MASS[num].age);
	int j = 0, k = 0;
	char c;
	while ((c = MASS[num].name[j]) != '\0')
	{
		printf("%c", c);
		j++;
	}
	printf(" ");
	while ((c = MASS[num].surname[k]) != '\0')
	{
		printf("%c", c);
		k++;
	}
	printf("\n");
	free(MASS);
	fclose(A);
	printf("\n");
	system("pause");
	return 0;
}

