#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <conio.h>
#include "User.h"
#include "CurrentMes.h"
#include "Func.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	User user;
	CurrentMessages cm;
	bool enter{ true };
	while (true)
	{
		std::cout << "ДОБРОГО ВРЕМЕНИ СУТОК, УВАЖАЕМЫЙ КЛИЕНТ. ПРОГРАММА <ЧАТ-МЕССЕНДЖЕР> ПРИВЕТСТВУЕТ ВАС." << '\n';
		std::cout << "ВВЕДИТЕ ЛОГИН И ПАРОЛЬ ДЛЯ ВХОДА В ПРОГРАММУ ИЛИ ПРОЙДИТЕ РЕГИСТРАЦИЮ." << '\n';
		std::cout << "Вход в программу - 1, регистрация - 2" << '\n';


		int xy{};
		std::cout << '\n';
		std::cout << "Введите код операции: ";
		std::cin >> xy;
		std::cout << '\n';
		switch (xy)
		{
		case 1:
		again:
			if (user.getIndLogPasswFromFile() == true)
			{
				system("cls");
				std::cout << '\n';
				std::cout << "КАКУЮ ОПЕРАЦИЮ ВЫ ХОТИТЕ ВЫПОЛНИТЬ?" << '\n';
				std::cout << '\n';
				bool repeat{ true };
				while (true)
				{
					std::cout << "Просмотреть список контактов - 3;" << '\n';
					std::cout << "Написать конкретному пользователю - 4;" << '\n';
					std::cout << "Написать всем пользователям - 5;" << '\n';
					std::cout << "Прочитать свои и адресованные Вам сообщения - 6;" << '\n';
					std::cout << "Прочитать общие сообщения для всех пользователей - 7;" << '\n';
				
					int ax{};
					std::cout << '\n';
					std::cout << "Введите код операции: ";
					std::cin >> ax;
					std::cout << '\n';
					switch (ax)
					{
					case 3:
						user.getListUsersFromFile();
						break;
					case 4:
						cm.createPersonalMessages();
						break;
					case 5:
						cm.createMessagesToAll();
						break;
					case 6:
						do
						{
							user.controlPhone;
							cm.word;
							cm.searchPersonalMesssages();
							if (user.controlPhone == cm.word)
							{
								cm.getPersonalMessages();
								cm.cleanFile();
							}
							else
							{
								std::cout << "Вы пытаетесь получить доступ к частной переписке других пользователей. В доступе отказано" << '\n';
								cm.cleanFile(); /*эту функцию приходится вставлять дважды, чтобы предотвратить вывод
												посторонних сообщений*/
							}

						} while (user.controlPhone != cm.word);
						break;

					case 7:
						cm.getMessagesToAll();
						break;
					}
					int z{};
					std::cout << '\n';
					std::cout << "Желаете выполнить еще одну операцию? Да - нажмите '1', нет - нажмите '0'" << '\n';
					std::cin >> z;
					if (z == 1)
					{
						repeat = true;
					}
					else
					{
						repeat = false;
						break;
					}
					system("cls");
				}
			}
			else
			{
				std::cout << "Неверный логин или пароль. Введите правильное значение " << '\n';
				goto again;
				break;
			}
			break;
		case 2:
			std::cout << "Пожалуйста, зарегистрируйтесь: " << '\n';
			std::cout << '\n';
			user.FillArray();
			std::cout << '\n';
			std::cout << "Регистрация завершена успешно." << '\n';
			break;
		}
		int zx{};
		std::cout << '\n';
		std::cout << "Вернуться в начало программы - 1, Выход - 0" << '\n';
		std::cin >> zx;
		if (zx == 1)
		{
			enter = true;
		}
		else
		{
			enter = false;
			break;
		}
		system("cls");

	}
	return 0;
}
