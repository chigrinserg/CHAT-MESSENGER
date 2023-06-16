#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "Func.h"

std::string CurrentMessages::curTime()
{
	time_t timep;
	struct tm* p;
	time(&timep); // Получаем, сколько секунд прошло с 1970 года, и сохраняем его в timep типа time_t
	p = localtime(&timep);// Используем localtime для преобразования количества секунд в структуру struct tm
	int day = p->tm_mday;
	int mon = 1 + p->tm_mon;
	int year = 1900 + p->tm_year;
	int hour = p->tm_hour;
	int min = p->tm_min;
	int sec = p->tm_sec;
	std::string currentTime = (std::to_string(day) + "." + std::to_string(mon) + "." + std::to_string(year) + "_" + std::to_string(hour) + ":"
		+ std::to_string(min) + ":" + std::to_string(sec));
	return currentTime;
}

std::string autoPfone() //функция установки маски ввода телефонного номера
{
	std::cout << "Введите номер телефона: " << '\n';
	int length = 0;
	int pospos = 0;
	int posarrays[10] = { 3,4,5,7,8,9,11,12,14,15 };
	int pos = posarrays[pospos];
	char mask[17] = "+7(***)***-**-**";
	printf("%s", mask);
	while (length != 10) {
		int ch = _getch();
		if (ch >= '0' && ch <= '9') {
			length++;
			mask[pos] = ch;
			system("cls");
			pospos++;
			pos = posarrays[pospos];
			printf("%s", mask);
		}
	}
	return mask;
}





