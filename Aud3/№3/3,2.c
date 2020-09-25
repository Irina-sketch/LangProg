#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include<windows.h>
#include<locale.h>
#include<ctype.h>

int row(FILE *G) //кол-во сток в файле
{
	int m = 1;
	char tmp;
	while (!feof(G))
	{
		if (fscanf_s(G, "%c", &tmp, 1) == 1)
		{
			if (tmp == 10)
			{
				m++;
			}
		}
		else
		{
			break;
		}
	}
	fseek(G, 0, SEEK_SET);
	return m;
}

int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	char *mas, *mas1, *mas2;
	int i = 0, k = 1, j = 0, m, n = 0, count = 0;
	mas = (char*)malloc(1 * sizeof(char));
	FILE *z;
	fopen_s(&z, "G.txt", "r");
	m = row(z);
	mas1 = (char*)malloc((m * 2) * sizeof(char));
	mas2 = (char*)malloc((m * 2) * sizeof(char));
	fseek(z, 0, SEEK_SET);
	while (!feof(z))
	{
		fscanf_s(z, "%c", &mas[n], 1);
		n++;
		mas = (char*)realloc(mas, (n + 1) * sizeof(char));
	}
	mas[n - 1] = '\0';
	mas1[0] = mas[0];
	for (i = 1; i < n + 1; i++)
	{
		if (mas[i] == '\n')
		{
			mas2[j] = mas[i - 1];
			j++;
			mas1[k] = mas[i + 1];
			k++;
		}
		else if (mas[i] == '\0')
		{
			mas2[j] = mas[i - 1];
			j++;
			mas2[j + 1] = '\0';
			mas1[k] = '\0';
		}
	}
	fclose(z);
	for (i = 0; i < j; i++)
	{
		for (n = 0; n < k; n++)
		{
			if ((int)(mas2[n] - 32) == (int)mas1[i])
			{
				count++;
			}
		}
	}
	if (count == m || count == m - 1)
	{
		printf("Да\n");
	}
	else
	{
		printf("Нет\n");
	}
	free(mas);
	free(mas1);
	free(mas2);
	system("pause");
	return 0;
}