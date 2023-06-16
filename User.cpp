#include <iostream>
#include<string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include<ios>
#include "User.h"


User::User() {}
User::User(std::string& phone, std::string& family, std::string& name, std::string& patr, std::string& log, std::string& pass)
    : m_phone{ phone }, m_family{ family }, m_name{ name }, m_patr{ patr }, m_log{ log }, m_pass{ pass }{}
User::~User() {}

void User::setUsers()
{
    std::cout << " Телефон: ";
    m_phone= autoPfone();
    std::cout << '\n';
    std::cout << " Фамилия: ";
    std::cin >> m_family;
    std::cout << "     Имя: ";
    std::cin >> m_name;
    std::cout << "Отчество: ";
    std::cin >> m_patr;
    std::cout << "Придумайте себе логин и пароль. Никому не сообщайте их" << '\n';
    std::cout << "   Логин: ";
    std::cin >> m_log;
    std::cout << "  Пароль: ";
    std::cin >> m_pass;
    std::cout << '\n';
}
void User::getUsers()
{
    std::cout << "=========================================================================================" << '\n';
    std::cout << "  Телефон: " << m_phone << '\n';
    std::cout << "  Фамилия: " << m_family << '\n';
    std::cout << "      Имя: " << m_name << '\n';
    std::cout << " Отчество: " << m_patr << '\n';
    std::cout << "    Логин: " << m_log << '\n';
    std::cout << "   Пароль: " << m_pass << '\n';
    std::cout << "=========================================================================================" << '\n';
}

void User::getListUsers() //просмотр пользователем списка контактов
{
    std::cout << "=========================================================================================" << '\n';
    std::cout << "  Телефон: " << m_phone << '\n';
    std::cout << "  Фамилия: " << m_family << '\n';
    std::cout << "      Имя: " << m_name << '\n';
    std::cout << " Отчество: " << m_patr << '\n';
    std::cout << "=========================================================================================" << '\n';
}

std::string User::getFamily() const
{    return m_family;}

std::string User::getName() const
{    return m_name;}

std::string User::getPatr() const
{    return m_patr;}

std::string User::getPhone() const
{    return m_phone;}

std::string User::getLog() const
{    return m_log;}

std::string User::getPass() const
{    return m_pass;}

bool User::operator==(const User& obj2) const
{
    if (this->getPhone().compare(obj2.getPhone()) == 0)
        return true;
    else
        return false;
}
std::ostream& operator<< (std::ostream& out, const User& user)
{
    out << user.m_phone << " " << user.m_family << " " << user.m_name << " " << user.m_patr << " " << " " << user.m_log << " " << user.m_pass; // причем тип функции также ссылочный, и воз-вращает параметр out в качестве возвращаемого типа
    return out;
}
std::istream& operator>> (std::istream& in, User& user)
{
    in >> user.m_phone;
    in >> user.m_family;
    in >> user.m_name;
    in >> user.m_patr;
    in >> user.m_log;
    in >> user.m_pass;
    return in;
}

int size2{ 1 };
std::vector<User> arr(size2);    //объявляем массив экземпляров класса User
User user;                      //объявляем первый экземпляр класса

void User::FillArray() //функция создания списка пользователей
{
    std::cout << "РЕГИСТРАЦИЯ  НОВОГО  ПОЛЬЗОВАТЕЛЯ: " << '\n';
    std::cout << '\n';
    for (int i = 0; i < size2; ++i) 
    {
        arr[i].setUsers();
    }
    for (int j = 0; j < size2; ++j) /* второй цикл позволяет добавлять новых пользователей
                                      инкрементируя размер массива через функцию push_backв */
    {
        int z{};
        std::cout << "Добавить пользователя? Да - 1, Нет - 0" << '\n';
        std::cin >> z;
        if (z == 1)
        {
            ++size2;
            user.setUsers();
            arr.push_back(user);
        }
        else
            break;
    }
    for (int i = 0; i < (end(arr) - begin(arr)); ++i) //выводим созданный массив на консоль
    {
        arr[i].getUsers();
    }
    std::ofstream out("listOfUsers.txt", std::ios::app); //сохраняем массив в текстовый файл
    for (int i = 0; i < (end(arr) - begin(arr)); ++i)
    {
        out << arr[i] << '\n';
    }
    std::cout << '\n';
}

int User::Get_records_in_file(const std::string name_file) /*Подсчет числа строк в файле списка пользователей
                                                           для введения этого числа в качестве размера массива
                                                           вывода списка в консоль*/
{
    int count = 0;
    std::ifstream input_file("listOfUsers.txt");
    std::string s;
    while (!input_file.eof())
    {
        getline(input_file, s);
        ++count;
    }
    input_file.close();
    return count;
}

void User::getListUsersFromFile() //функция извлечения из файла списка контактов без логина и пароля
{
    std::cout << "СПИСОК ДОСТУПНЫХ КОНТАКТОВ: " << '\n';
    std::cout << '\n';
    std::vector<User> arr(User::Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    std::string str;
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        input_file >> arr[i];
    }
    input_file.close();
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        arr[i].getListUsers();
    }
}

bool User::getIndLogPasswFromFile() //функция извлечения из файла личного логина и пароля
{
    std::vector<User> arr(Get_records_in_file("listOfUsers.txt"));
    std::ifstream input_file("listOfUsers.txt");
    std::string str;
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        input_file >> arr[i];
    }
    input_file.close();
    std::string login;
    std::cout << "Введите логин: ";
    std::cin >> login;
    std::string password;
    std::cout << "Введите пароль: ";
    std::cin >> password;
    for (int i = 0; i < (Get_records_in_file("listOfUsers.txt")); ++i)
    {
        if (login == arr[i].getLog() && password == arr[i].getPass())
        {
            controlPhone = arr[i].getPhone();
            return true;
        }
        
    }
}




