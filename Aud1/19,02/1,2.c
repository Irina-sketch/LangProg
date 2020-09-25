#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<Windows.h>
int main()
{
	int a = 0, c, n = 0;
	int* mass;
	mass = (int*)malloc(a * sizeof(int));
	printf_s("input length (1 to 10)\n");
	scanf_s("%d", &a);
	if (a < 1 && a>10)
	{
		printf_s("try again");
		return 0;
	}
	do
	{
		c = _getch();
		if (c == 8)
		{
			printf("\b \b");
			n--;
			continue;
		}
		if (c == 13)
			break;
		mass[n] = c;
		printf("*");
		c = toupper(c);
		n = n + 1;
	} while (n != a);
	n = 0;
	printf("\n");
	printf_s("password:");
	for (int i = 0; i < a; i++)
		printf_s("%c", mass[i]);
	free(mass);
	system("pause");
}
