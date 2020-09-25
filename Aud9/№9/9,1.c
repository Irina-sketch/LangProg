#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock.h>
#include <locale.h>
#include <time.h>
#define INFO_SIZE 50 //длина для строк имен

int main()
{
	TCHAR infoBuf[INFO_SIZE];//char
	DWORD bufCharCount = INFO_SIZE;//Выделяет и при необходимости инициализирует двойное слово хранилища для каждого инициализатора.
	struct tm time_date;
	time_t long_time = time(NULL);// show time
	char timebuf[26];

	GetUserName(infoBuf, &bufCharCount);
	wprintf(L"User name: %s\n", infoBuf);// printf  для широких символов
	bufCharCount = INFO_SIZE;

	GetComputerName(infoBuf, &bufCharCount);
	wprintf(L"Computer name: %s\n", infoBuf);
	bufCharCount = INFO_SIZE;

	localtime_s(&time_date, &long_time);
	printf("Time: %d:%d:%d\n", time_date.tm_hour, time_date.tm_min, time_date.tm_sec);
	printf("Date: %d ", time_date.tm_mday);
	
	GetWindowsDirectory(infoBuf, INFO_SIZE);
	wprintf(L"Directory Windows: %s\n", infoBuf);
	bufCharCount = INFO_SIZE;
	system("pause");
	return 0;
}