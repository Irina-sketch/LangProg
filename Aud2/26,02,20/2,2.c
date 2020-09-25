#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	char a = 0;
	while (a != '\n')
	{
		a = getchar();
		if ((a >= 48) && (a <= 57))
		{
			int t;
			if (a == 48)
				t = 0;
			if (a == 49)
				t = 1;
			if (a == 50)
				t = 2;
			if (a == 51)
				t = 3;
			if (a == 52)
				t = 4;
			if (a == 53)
				t = 5;
			if (a == 54)
				t = 6;
			if (a == 55)
				t = 7;
			if (a == 56)
				t = 8;
			if (a == 57)
				t = 9;
			t=t*t ;
			printf("%d ", t);
		}
	}
	system("pause");
	return(0);
}