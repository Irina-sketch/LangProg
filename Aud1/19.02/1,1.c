#include<stdio.h> 
#include<stdlib.h> 
#include<windows.h> 
typedef struct {
	int a;
	int b;
	int abs;
}complex;
int main()
{
	FILE* in;
	fopen_s(&in, "input.txt", "r");
	fseek(in, 0, SEEK_SET);
	int number = 0, x = 0, y = 0, abs = 0, max = 0, count = 0;
	fscanf_s(in, "%d", &number);
	complex* compl = (complex*)malloc(number * sizeof(complex));
	for (int i = 0; i < number; i++)
	{
		fscanf_s(in, "%d", &x);
		fscanf_s(in, "%d", &y);
		compl[i].a = x;
		compl[i].b = y;
		compl[i].abs = x * x + y * y;
	}
	for (int i = 0; i < number; i++)
	{
		if (compl[i].b < 0)
		{
			printf_s("%d", compl[i].a);
			printf_s("%di\n", compl[i].b);
			printf_s("sqrt(%d)\n", compl[i].abs);
		}
		else
		{
			printf_s("%d+", compl[i].a);
			printf_s("%di\n", compl[i].b);
			printf_s("sqrt(%d)\n", compl[i].abs);
		}
		printf("\n");
	}
	for (int i = 0; i < number; i++)
	{
		if (compl[i].abs > max)
		{
			max = compl[i].abs;
			count = i;
		}
	}
	printf_s("max:");
	if (compl[count].b < 0)
	{
		printf_s("%d", compl[count].a);
		printf_s("%di\n", compl[count].b);
	}
	else
	{
		printf_s("%d+", compl[count].a);
		printf_s("%di\n", compl[count].b);
	}

	free(compl);
	fclose(in);
	system("pause");
	return 0;
}
