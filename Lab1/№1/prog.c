#include"Func.h"
#include<stdio.h>
#include<stdlib.h>



int main()
{
	setlocale(LC_ALL, "RUS");
	int i = 0, j = 0, size = 0, size1, number;
	long long int determinant;
	errno_t err;//����� ������
	clock_t start, end;
	struct mas
	{
		int **matrix;
	};
	struct mas Mas;

	Memory *head = (Memory*)malloc(sizeof(Memory)), *P;
	head->next = NULL;
	head->Size = 0;

	while (1)
	{
		printf("������� 1, ����� ������ ������� � ����������.\n������� 2, ����� ����� ������� �� �����.\n������� 3, ����� ��������� ��������� �������.\n������� 4, ����� ����� �� ���������.\n");
		if (scanf_s("%d", &number) == 0)
		{
			printf("������������ ����\n");
			system("pause");
			exit(1);
		}
		if (number == 1)
		{
			printf("������� ������ �������: ");
			if (scanf_s("%d", &size) == 0)
			{
				printf("������������ ����\n");
				system("pause");
				exit(1);
			}
			if (size < 1)
			{
				printf("������������ ��������� ����������!\n");
				system("pause");
				exit(1);
			}
			if (size > 12)
			{
				printf("������� ������ �������!\n");
				system("pause");
				exit(1);
			}
			Mas.matrix = (int**)malloc(size * sizeof(int*));
			for (i = 0; i < size; i = i + 1)
			{
				Mas.matrix[i] = (int*)malloc(size * sizeof(int));
			}
			for (i = 0; i < size; i = i + 1)
			{
				for (j = 0; j < size; j = j + 1)
				{
					printf("�������[%d][%d]= ", i, j);
					if (scanf_s("%d", &Mas.matrix[i][j]) == 0)
					{
						printf("������������ ����\n");
						system("pause");
						exit(1);
					}
					if (Mas.matrix[i][j] < -99 || Mas.matrix[i][j]>99)
					{
						printf("������� ������� �����!\n");
						system("pause");
						exit(1);
					}
				}
			}
			printf("�������� �������:\n");
		}
		else if (number == 2)
		{
			FILE *in;
			err = fopen_s(&in, "input.txt", "r");
			if (err != NULL)
			{
				printf("����: input.txt\n��� ������: %d\n", err);
				perror("��������");
				system("pause");
				exit(1);
			}
			if (SYMBOL(in) == 1) {
				system("pause");
				exit(1);
			}
			if (SPACE(in) == 1) {
				system("pause");
				exit(1);
			}
			if (LongNumber(in) == 1) {
				system("pause");
				exit(1);
			}
			size = ROW(in);
			size1 = COLUMN(in);
			if (size == size1)
			{
				if (size > 12)
				{
					printf("������� ������� ������!\n");
					system("pause");
					exit(1);
				}
				Mas.matrix = (int**)malloc(size * sizeof(int*));
				for (i = 0; i < size; i = i + 1)
				{
					Mas.matrix[i] = (int*)malloc(size * sizeof(int));
				}
				printf("������ �������: %d\n", size);
				for (i = 0; i < size; i = i + 1)
				{
					for (j = 0; j < size; j = j + 1)
					{
						fscanf_s(in, "%d", &Mas.matrix[i][j]);
						if (Mas.matrix[i][j] > 99)
						{
							printf("������� �����!\n");
							system("pause");
							exit(1);
						}
					}
				}
				printf("������� �� �����:\n");
			}
			else
			{
				printf("������� �� ����������.\n");
				system("pause");
				exit(1);
			}
		}
		else if (number == 3)
		{
			srand((int)time(0));
			printf("������� ������ �������: ");
			if (scanf_s("%d", &size) == 0)
			{
				printf("������������ ����\n");
				system("pause");
				exit(1);
			}
			if (size < 1)
			{
				printf("������������ ��������� ����������!\n");
				system("pause");
				exit(1);
			}
			if (size > 12)
			{
				printf("������� ������ �������!\n");
				system("pause");
				exit(1);
			}
			Mas.matrix = (int**)malloc(size * sizeof(int*));
			for (i = 0; i < size; i = i + 1)
			{
				Mas.matrix[i] = (int*)malloc(size * sizeof(int));
			}
			printf("������ �������: %d\n", size);
			for (i = 0; i < size; i = i + 1)
			{
				for (j = 0; j < size; j = j + 1)
				{
					Mas.matrix[i][j] = -9 + rand() % 19;
				}
			}
			printf("��������� �������:\n");
		}
		else if (number == 4)
		{
			exit(1);
		}
		else
		{
			printf("������������ ����\n");
			system("pause");
			exit(1);
		}
		PrintMatrix(Mas.matrix, size);
		printf("���������� ������������ ������� �������� ���������� �� ������� �������:\n");
		P = SearchMatrix(head, size, Mas.matrix);
		if (P == NULL)
		{
			start = clock();
			determinant = GetDeterminant(Mas.matrix, size);
			end = clock();
			if (head->next == NULL)
			{
				head->Determinant1 = determinant;
				head->Size = size;
				head->matrix1 = (int**)malloc(size * sizeof(int*));
				for (i = 0; i < size; i = i + 1)
				{
					head->matrix1[i] = (int*)malloc(size * sizeof(int));
				}
				for (i = 0; i < size; i = i + 1)
				{
					for (j = 0; j < size; j = j + 1)
					{
						head->matrix1[i][j] = Mas.matrix[i][j];
					}
				}
				head->next = (Memory*)malloc(sizeof(Memory));
				head->next->next = NULL;
				head->next->Size = 0;//���� �� ������� ������� � ������, ��  size= 0 ,����������� ������� ������� �� �������� � ������ ������
			}
			else
			{
				MemoryDeterminant(head, Mas.matrix, size, determinant);
			}
		}
		else
		{
			start = clock();
			determinant = P->Determinant1;
			end = clock();
		}
		printf("������������ ������� �����: %lld\n", determinant);
		printf("����� ���������� ������������: %f ������\n", ((float)end - start) / (float)CLOCKS_PER_SEC);
		for (i = 0; i < size; i = i + 1)
		{
			free(Mas.matrix[i]);
		}
		free(Mas.matrix);
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}